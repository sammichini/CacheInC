// prob 7-1 by Sequoia
#include <stdio.h>
#define UI unsigned int


UI getOffset(UI address){

    UI mask = 0x000000FF;
    // grab byte 0 w/ a mask to find offset
    UI offset = address & mask;
    return offset;

}

UI getTag(UI address) {
    UI mask = 0xFFFFF000;
    UI tag = address & mask;
    // divide tag by 2^12 with right shift after masking
    // gives us correct tag
    tag >>= 12;
    return tag;
}


UI getSet(UI address) {
    UI mask = 0x00000F00;
    UI set = address & mask;
    // grab nibble 1.1 then mask, right shift by 8 (divide by 2^8)
    // returns correct set value
    set >>= 8;
    return set;
}



int main()
{
    // print offset, tag, set
    UI address = 0x12345678;
    UI offset = getOffset(address);
    printf("Address: 0x%08x\n", address);
    printf("Offset: %02x\n", offset);
    UI tag = getTag(address);
    printf("Tag: %01x\n", tag);
    UI set = getSet(address);
    printf("Set: %1x\n", set);


    // print offset, tag, set
    address = 0x87654321;
    printf("\nAddress: 0x%08x\n", address);
    offset = getOffset(address);
    printf("Offset: %02x\n", offset);
    tag = getTag(address);
    printf("Tag: %1x\n", tag);
    set = getSet(address);
    printf("Set: %1x\n", set);


    return 0;
}
