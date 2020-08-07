# Copyright (c) 2020, QuantStack and Mamba Contributors
#
# Distributed under the terms of the BSD 3-Clause License.
#
# The full license is in the file LICENSE, distributed with this software.

### Initialize autoconf

# Require the latest version of autoconf
AC_PREREQ([2.69])

# Provide information about package and version numbering
AC_INIT(mamba, m4_esyscmd_s([awk -e '/^Version:/ {print $2}' DESCRIPTION]))

# Verify the correct src directory exists from where the file is being run.
AC_CONFIG_SRCDIR([src])
