/*++****************************************************************************
*
*	Name: i2c_utils.h
*  
*	Description: Common I2C operations
*
*	Revision History:
*	Date	Who	Comments	
*	------	---	---------------------------------------------------------------
*	110727	DHT	Created
****************************************************************************--*/

#ifndef NECAL_I2C_UTILS_H
#define NECAL_I2C_UTILS_H

// supported clock rates
#define I2C_CLK_FREQ_LOW		10000
#define I2C_CLK_FREQ_50K		50000
#define I2C_CLK_FREQ_STANDARD	100000
#define I2C_CLK_FREQ_FAST		400000
#define I2C_CLK_FREQ_FAST_PLUS	1000000
#define I2C_CLK_FREQ_HIGH		3400000	

#define I2CUtils_Get7BitAddrWrite(addr)	((addr << 1) | I2C_WRITE)
#define I2CUtils_Get7BitAddrRead(addr)	((addr << 1) | I2C_READ)

INT32 I2CUtils_InitPort(I2C_MODULE module, UINT32 pbClk, BOOL useFastSpeed);
BOOL I2CUtils_IsBusIdle(I2C_MODULE module, UINT32 timeOutMs);
INT32 I2CUTils_StartTransfer(I2C_MODULE module, BOOL restart, UINT32 timeOutMs);
INT32 I2CUTils_StopTransfer(I2C_MODULE module, UINT32 timeOutMs);
BOOL I2CUTils_TransmitByte(I2C_MODULE module, UINT8 data);
INT32 I2CUTils_WriteBytes(I2C_MODULE module, UINT8 slaveAddress, UINT8 *data, UINT8 len, UINT32 timeoutMs);
INT32 I2CUTils_TransmitBytes(I2C_MODULE module, UINT8 slaveAddress, UINT8 *writeData, UINT8 writeLen, UINT8 *readData, UINT8 readLen, UINT32 timeoutMs);
inline BOOL I2CUTils_WriteToRegister(I2C_MODULE module, UINT8 slaveAddr, UINT8 regAddr, UINT8 val);
inline BOOL I2CUTils_ReadFromRegister(I2C_MODULE module, UINT8 slaveAddr, UINT8 regAddr, UINT8 *val);
BOOL I2CUtils_ReadByte(I2C_MODULE module, UINT8 *data, BOOL doAck, BOOL ack);

#define I2CUTILS_CODE_SUCCESS					0
#define I2CUTILS_CODE_TIMEOUT					1
#define I2CUTILS_CODE_START_FAILED				2
#define I2CUTILS_CODE_BYTE_TRANSMIT_FAILED		3
#define I2CUTILS_CODE_BYTE_READ_FAILED			4

#endif

