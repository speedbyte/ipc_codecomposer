#define EEPROM_LAYOUT_OFFSET_MASK_0_31 \
/* Y_0 if ( i == 0 )  {	Offset = 0;	} */ \
/* Y_0 if ( i == 1 )  {	Offset = 0;	} */ \
/* Y_0 if ( i == 2 )  {	Offset = 0;	} */ \
/* Y_0 if ( i == 3 )  {	Offset = 0;	} */ \
/* Y_0 if ( i == 4 )  {	Offset = 0;	} */ \
/* Y */ if ( i == 5 )  {	Offset = 10;	} \
/* Y_0 if ( i == 6 )  {	Offset = 0;	} */ \
/* Y_0 if ( i == 7 )  {	Offset = 0;	} */ \
/* Y_0 if ( i == 8 )  {	Offset = 0;	} */ \
/* Y_0 if ( i == 9 )  {	Offset = 0;	} */ \
/* Y */ if ( i == 13 )  {	Offset = 15;	} \
/* Y */ if ( i == 14 )  {	Offset = 8;	} \
/* Y */ if ( i == 15 )  {	Offset = 1;	} \




#define EEPROM_LAYOUT_OFFSET_MASK_32_63 \
/* Y_0 if ( i == 32 )  {	Offset = 0;	} */ \
/* Y */ if ( i == 52 )  {	Offset = 21;	} \




#define EEPROM_LAYOUT_LENGTH_MASK_0_31 \
/* Y if ( i == 0 )  {	Length = 32;	} */ \
/* Y if ( i == 1 )  {	Length = 32;	} */ \
/* Y if ( i == 2 )  {	Length = 32;	} */ \
/* Y if ( i == 3 )  {	Length = 32;	} */ \
/* Y */ if ( i == 4 )  {	Length = 31;	} \
/* Y */ if ( i == 5 )  {	Length = 22;	} \
/* Y if ( i == 6 )  {	Length = 32;	} */ \
/* Y if ( i == 7 )  {	Length = 32;	} */ \
/* Y if ( i == 8 )  {	Length = 32;	} */ \
/* Y */ if ( i == 9 )  {	Length = 20;	} \
/* Y */ if ( i == 13 )  {	Length = 11;	} \
/* Y */ if ( i == 14 )  {	Length = 2;	} \
/* Y */ if ( i == 15 )  {	Length = 1;	} \




#define EEPROM_LAYOUT_LENGTH_MASK_32_63 \
/* Y */ if ( i == 32 )  {	Length = 1;	} \
/* Y */ if ( i == 52 )  {	Length = 4;	} \




/* End Of File EEPROM_LAYOUT_generated_H2.h */
