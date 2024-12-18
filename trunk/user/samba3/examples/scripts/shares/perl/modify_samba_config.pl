#!/usr/bin/perl

######################################################################
##
##  Simple add/delete/change share command script for Samba
##
##  Copyright (C) Gerald Carter                2004.
##
##  This program is free software; you can redistribute it and/or modify
##  it under the terms of the GNU General Public License as published by
##  the Free Software Foundation; either version 2 of the License, or
##  (at your option) any later version.
##
##  This program is distributed in the hope that it will be useful,
##  but WITHOUT ANY WARRANTY; without even the implied warranty of
##  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##  GNU General Public License for more details.
##
##  You should have received a copy of the GNU General Public License
##  along with this program; if not, write to the Free Software
##  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
##
######################################################################

use POSIX qw(tmpnam);

##
## local variables
##
my $delete_mode = undef;
my $add_mode = undef;
my $tmp_file_name = undef;


## check for correct parameters
if ($#ARGV == 1) {
	$delete_mode = 1;
}
elsif ($#ARGV == 4) {
	$add_mode = 1;
}
else {
	print "Usage: $0 configfile share [path] [comment]\n"; 
	exit -1;
}

## first param is always the config file
open (CONFIGFILE, "$ARGV[0]") || die "Unable to open $ARGV[0] for reading!\n";

## FIXME!!  Right now we throw away all comments in the file.
while (<CONFIGFILE>) {

	chomp($_);
	
	## eat leading whitespace
	$_ =~ s/^\s*//;
	
	## eat trailing whitespace
	$_ =~ s/\s*$//;
	

	## throw away comments
	next if (($_ =~ /^#/) || ($_ =~ /^;/));

	## set the current section name for storing the hash
	if ($_ =~ /^\[.*\]$/) {
	
		$_ = substr($_, 1, length($_)-2);
		
		if ( length($_) ) {
			$section = $_;
		}
		else {
			print "Bad Section Name - no closing ]\n";
			exit -1;
		}

		next;
	}	
	
	## check for a param = value
	if ($_ =~ /=/) {
		($param, $value) = split (/=/, $_,2);
		$param =~ s/./\l$&/g;
		$param =~ s/\s+//g;
		$value =~ s/^\s+//;
		
		$config{$section}{$param} = $value;
		
		next;
	}

	## should have a hash of hashes indexed by section name
}
close (CONFIGFILE);

##
## We have the smb.conf in our hash of hashes now.
## Add or delete 
##
if ($add_mode) {
	$config{$ARGV[1]}{'path'} = $ARGV[2];
	$config{$ARGV[1]}{'comment'} = $ARGV[3];
	$config{$ARGV[1]}{'max connections'} = $ARGV[4];
}
elsif ($delete_mode) {
	delete $config{$ARGV[1]};
}

##
## Print the resulting configuration
##
#do {
#	$tmp_file_name = tmpnam();
#	print "Using temporary file - $tmp_file_name\n";
#} while (!sysopen(TMP, $tmp_file_name, O_RDWR|O_CREAT|O_EXCL));
$tmp_file_name = tmpnam();
open (TMP, ">$tmp_file_name") || die "Unable to open temporary file for writing!\n";

PrintConfigFile(TMP);

## now overwrite the original config file
close (TMP);
system ("cp -pf $ARGV[0] $ARGV[0].bak");
system ("cp -pf $tmp_file_name $ARGV[0]");
unlink $tmp_file_name; 


exit 0;





#######################################################################################
## PrintConfigFile()
##
sub PrintConfigFile {
	my ($output) = @_;

	## print the file back out, beginning with the global section
	print $output "#\n# Generated by $0\n#\n";

	PrintSection ($output, 'global', $config{'global'});

	foreach $section (keys %config) {

		if ("$section" ne "global") {
			print $output "## Section - [$section]\n";
			PrintSection ($output, $section, $config{$section});
		}
	}

	print $output "#\n# end of generated smb.conf\n#\n";
}

#######################################################################################
## PrintSection()
##
sub PrintSection {
	my ($outfile, $name, $section) = @_;

	print $outfile "[$name]\n";
	foreach $param (keys %$section) {
		print $outfile "\t$param".' 'x(25-length($param)). " = $$section{$param}\n";
	}
	print $outfile "\n";

}
