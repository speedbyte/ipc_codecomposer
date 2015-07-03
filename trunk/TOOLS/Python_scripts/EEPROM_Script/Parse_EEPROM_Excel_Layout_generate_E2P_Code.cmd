@echo OFF
@rem -----------------------------------------------------
@rem  Copyright (c) 2010 S1nn GmbH & Co. KG.
@rem  All Rights Reserved.
@rem To generate header files only type -g before %1

echo Please type "START" and then enter to start generating the files.

python Parse_EEPROM_Excel_Layout.py -g %1

pause