################################################################################
################### Copyright (c) 2008 by S1nn GmbH & Co. KG  ##################
############################  All Rights Reserved  #############################
################################################################################

################################################################################
# * File Name:     makefile
# *-----------------------------------------------------------------------------
# * Module Name:
# *-----------------------------------------------------------------------------
# * Description:
#-----------------------------------------------------------------------------
# $Date: 2010-04-15 09:26:23 +0200 (Do, 15 Apr 2010) $
# $Rev: 12200 $
# $Author: agrawal $
# $URL: http://subversion-01/svn/SW_HW_System/Plattform/TMS470/MOD/MOD_SPI/tags/PLATFORM_TMS470_MOD_SPI_B_10.13_pre/makefile $
#-----------------------------------------------------------------------------
################################################################################

# For a full build in cygnus bash shell type :
#   > make clean
#   > make
#
# Global project options are set in makeopts at top level of project tree.
# Each lower level makefile must define TOP as the relative path to the top
# of the project tree.  This allows all tools to run from within the project
# structure (and to be included in the project for version control!).
# All lower make files should include a clean definition which deletes all
# buildable objects.
#
# Make will build the specified targets (all is the default) in the list of
# subdirectories provided. This Makefile is for GNU make.

# define top directory relative to this working directory
TOP = ../../
# include global make options
include $(TOP)/BUILD/SYS/makeopts

# Define the subdirectories in which to run "make".
SUBDIRS = src

# Define targets 

all   : Makefile FORCE
	${MAKE} ${SUBDIRS} TARGET=$@

clean : Makefile  FORCE
	${MAKE} ${SUBDIRS} TARGET=$@
	-$(RM) -f *.bak *~

# Nested calls to make in the subdirectories
${SUBDIRS}: FORCE
	$(ECHO)
	$(ECHO) Working in directory $@
	cd $@; \
	../${MAKE} $(TARGET)

FORCE:

# End of File makefile