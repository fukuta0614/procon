use strict;
use warnings;
use utf8;

open(F, "q2.txt");

my $t = <F>;
chomp($t);

unlink('q2.txt');

print $t;
