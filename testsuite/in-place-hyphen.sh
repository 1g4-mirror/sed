#!/bin/sh
# Verify that "-" is treated as a file name with --in-place.

# Copyright (C) 2015-2025 Free Software Foundation, Inc.

# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.

# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.

# You should have received a copy of the GNU General Public License
# along with this program.  If not, see <https://www.gnu.org/licenses/>.
. "${srcdir=.}/testsuite/init.sh"; path_prepend_ ./sed
print_ver_ sed

echo abc > ./- || framework_failure_
echo aXc > exp-out || framework_failure_

sed -i 's/b/X/' - > out 2> err || fail=1

compare exp-out ./- || fail=1
compare /dev/null err || fail=1

Exit $fail
