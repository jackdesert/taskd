#! /usr/bin/env perl
################################################################################
## taskd = Taskserver
##
## Copyright 2010 - 2014, Göteborg Bit Factory.
##
## Permission is hereby granted, free of charge, to any person obtaining a copy
## of this software and associated documentation files (the "Software"), to deal
## in the Software without restriction, including without limitation the rights
## to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
## copies of the Software, and to permit persons to whom the Software is
## furnished to do so, subject to the following conditions:
##
## The above copyright notice and this permission notice shall be included
## in all copies or substantial portions of the Software.
##
## THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
## OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
## FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
## THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
## LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
## OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
## SOFTWARE.
##
## http://www.opensource.org/licenses/mit-license.php
##
################################################################################

use strict;
use warnings;
use Test::More tests => 13;

# Create the data dir.
my $data = 'add_org.data';
qx{mkdir $data};
ok (-d $data, "Created $data");

my $output = qx{../src/taskd init --data $data 2>&1};
unlike ($output, qr/^ERROR/,         "'taskd init --data $data' - no errors");
ok (-d $data,                        "'$data' dir exists");
ok (-d $data.'/orgs',                "'$data/orgs' dir exists");

# Simple organization.
$output = qx{../src/taskd add --data $data org ORG 2>&1};
unlike ($output, qr/^ERROR/,         "'taskd add --data $data org ORG' - no errors");
ok (-d $data.'/orgs/ORG',            "'$data/orgs/ORG' dir exists");
ok (-d $data.'/orgs/ORG/groups',     "'$data/orgs/ORG/groups' dir exists");
ok (-d $data.'/orgs/ORG/users',      "'$data/orgs/ORG/users' dir exists");

# Organization with a space in the name.
$output = qx{../src/taskd add --data $data org 'one two' 2>&1};
unlike ($output, qr/^ERROR/,         "'taskd add --data $data org \'one two\'' - no errors");
ok (-d $data.'/orgs/one two',        "'$data/orgs/one two' dir exists");
ok (-d $data.'/orgs/one two/groups', "'$data/orgs/one two/groups' dir exists");
ok (-d $data.'/orgs/one two/users',  "'$data/orgs/one two/users' dir exists");

# Cleanup.
qx{rm -rf $data};
ok (! -d $data, "Removed $data");

exit 0;

