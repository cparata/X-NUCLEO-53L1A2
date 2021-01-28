/**
 ******************************************************************************
 * @file    vl53l1_x_nucleo_53l1a2_class.h
 * @author  SRA
 * @version V1.0.0
 * @date    30-July-2020
 * @brief   Header file for component VL53L1 on X-NUCLEO-53L1A2
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT(c) 2020 STMicroelectronics</center></h2>
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *   1. Redistributions of source code must retain the above copyright notice,
 *      this list of conditions and the following disclaimer.
 *   2. Redistributions in binary form must reproduce the above copyright notice,
 *      this list of conditions and the following disclaimer in the documentation
 *      and/or other materials provided with the distribution.
 *   3. Neither the name of STMicroelectronics nor the names of its contributors
 *      may be used to endorse or promote products derived from this software
 *       without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 ******************************************************************************
*/

#ifndef __VL53L1_X_NUCLEO_53L1A2_CLASS_H
#define __VL53L1_X_NUCLEO_53L1A2_CLASS_H


/* Includes ------------------------------------------------------------------*/
#include "Arduino.h"
#include "vl53l1_class.h"
#include "stmpe1600_class.h"


/* Classes -------------------------------------------------------------------*/
/** Class representing a VL53L1 sensor component
 */
class VL53L1_X_NUCLEO_53L1A2 : public VL53L1 {
  public:
    /** Constructor (STMPE1600DigiOut)
     * @param[in] i2c device I2C to be used for communication
     * @param[in] &pin Gpio Expander STMPE1600DigiOut pin to be used as component GPIO_0 CE
     */
    VL53L1_X_NUCLEO_53L1A2(TwoWire *i2c, STMPE1600DigiOut *pin) : VL53L1(i2c, -1)
    {
      expgpio0 = pin;
    }

    /** Destructor
     */
    virtual ~VL53L1_X_NUCLEO_53L1A2() {}
    /* warning: VL53L1_X_NUCLEO_53L1A2 class inherits from GenericSensor, RangeSensor and LightSensor, that haven`t a destructor.
       The warning should request to introduce a virtual destructor to make sure to delete the object */

    int begin()
    {
      return expgpio0->begin();
    }

    int end()
    {
      return expgpio0->end();
    }

    /*** Interface Methods ***/
    /*** High level API ***/
    /**
     * @brief       PowerOn the sensor
     * @return      void
     */
    /* turns on the sensor */
    void VL53L1_On(void)
    {
      expgpio0->write(1);
      delay(10);
    }

    /**
     * @brief       PowerOff the sensor
     * @return      void
     */
    /* turns off the sensor */
    void VL53L1_Off(void)
    {
      expgpio0->write(0);
      delay(10);
    }

  protected:
    /* GPIO expander */
    STMPE1600DigiOut *expgpio0;
};


#endif /* __VL53L1_X_NUCLEO_53L1A2_CLASS_H */


