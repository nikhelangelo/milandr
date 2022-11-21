/*============================================================================================
 *
 *  (C) 2013, LDM-SYSTEMS
 *
 *  ���������������� ������ ��� ���������� ����� LDM-K1986BE92QI
 *
 *  ������ �� ��������������� "��� ����", �.�. ������������� ��� ������, ���������� ���������
 *  ������������� ���������� �� ���������� ��� ����������� Milandr K1986BE92QI. �������� LDM-SYSTEMS
 *  �� ����� ������� ��������������� �� ��������� ����������� ������������� �������, ���
 *  �������������� ������������� �� ��� ������, ��.
 *
 *  ������������ ��� Keil 5 DeamonClub.RU
 *
 *--------------------------------------------------------------------------------------------
 *
 *  ���� systick.c: ������� ������� ������ ��� ������ � ��������� ��������
 *
 *============================================================================================*/

#include "MDR32Fx.h"                    // Device header
//#include "MDR32F9Qx_config.h"           // Keil::Device:Startup_MDR1986BE9x
//#include "core_cm3.h"                   // Keil::Device:Startup_MDR1986BE9x

#include "systick.h"

// ������� �������� 
static vu32 TimerCounter = 0;

// ���������� ��������� �������� 
void SysTickStart(u32 ticks) {
    SysTick_Config(ticks);
}


void SysTickStop(void) {
    SysTick->CTRL &= ~SYSTICK_CSR_ENABLE;
}


// ���������� ���������� SYSTICK 
void SysTick_Handler(void) {
    if (TimerCounter)
        TimerCounter--;
}


// ������� �������� (�� ���� systick)
void SysTickDelay(u32 ticks) {
    if (ticks) {
        TimerCounter = ticks;
        SysTickStart(ticks);
        while (TimerCounter);
        SysTickStop();
    }
}


/*============================================================================================
 * ����� ����� systick.c
 *============================================================================================*/

