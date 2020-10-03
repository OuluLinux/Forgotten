#!/usr/bin/env python

# Runs fu with the correct configuration file for this checkout of Forgotten.

import os, sys

scriptdir = os.path.dirname(os.path.realpath(__file__))

fu = "%s/scripts/fu/fu" % (scriptdir,)
fuConfig = "%s/scripts/fu/fu.conf" % (scriptdir,)

# Run fu.
args = " ".join(sys.argv[1:])
args += " %s" % (fuConfig,)
os.system("%s %s" % (fu, args))

