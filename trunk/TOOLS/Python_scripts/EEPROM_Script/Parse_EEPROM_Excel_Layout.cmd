@echo OFF
@rem -----------------------------------------------------
@rem  Copyright (c) 2010 S1nn GmbH & Co. KG.
@rem  All Rights Reserved.
@rem -----------------------------------------------------

echo Please type "START" and then enter to start generating the files.

python Parse_EEPROM_Excel_Layout.py %1

pause