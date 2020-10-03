#!/usr/bin/env python

# This script is designed to configure a fu config file with the paths from
# this checkout of Forgotten.

import os

scriptdir = os.path.dirname(os.path.realpath(__file__))

fuConfigDefault = "%s/scripts/fu/fu.conf.default" % (scriptdir,)
fuConfig = "%s/scripts/fu/fu.conf" % (scriptdir,)

# Open the original file
with open(fuConfigDefault, "r") as default:
    with open(fuConfig, "w") as new:
        s = default.read()
        s = s.replace("$installRoot", "%s/images/local" % (scriptdir,))
        s = s.replace("$localDb", "%s/images/local/support/fu/db" % (scriptdir,))
        new.write(s)

print "Configuration file '%s' updated." % (fuConfig)

