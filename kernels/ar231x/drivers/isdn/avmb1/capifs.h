/* $Id: //depot/sw/linuxsrc/src/kernels/mips-linux-2.4.25/drivers/isdn/avmb1/capifs.h#1 $
 * 
 * Copyright 2000 by Carsten Paeth <calle@calle.de>
 *
 * This software may be used and distributed according to the terms
 * of the GNU General Public License, incorporated herein by reference.
 *
 */

void capifs_new_ncci(char type, unsigned int num, kdev_t device);
void capifs_free_ncci(char type, unsigned int num);
