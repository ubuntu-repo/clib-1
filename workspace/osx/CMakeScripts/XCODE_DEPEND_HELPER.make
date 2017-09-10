# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.Clib.Debug:
/Users/joseph.cameron/Workspace/clib/build/debug/Clib:
	/bin/rm -f /Users/joseph.cameron/Workspace/clib/build/debug/Clib


PostBuild.Clib.Release:
/Users/joseph.cameron/Workspace/clib/build/release/Clib:
	/bin/rm -f /Users/joseph.cameron/Workspace/clib/build/release/Clib


PostBuild.Clib.MinSizeRel:
/Users/joseph.cameron/Workspace/clib/workspace/osx/MinSizeRel/Clib:
	/bin/rm -f /Users/joseph.cameron/Workspace/clib/workspace/osx/MinSizeRel/Clib


PostBuild.Clib.RelWithDebInfo:
/Users/joseph.cameron/Workspace/clib/workspace/osx/RelWithDebInfo/Clib:
	/bin/rm -f /Users/joseph.cameron/Workspace/clib/workspace/osx/RelWithDebInfo/Clib




# For each target create a dummy ruleso the target does not have to exist
