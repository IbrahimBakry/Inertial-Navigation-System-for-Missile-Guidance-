#include "__cf_GP.h"
#ifndef RTW_HEADER_GP_acc_h_
#define RTW_HEADER_GP_acc_h_
#ifndef GP_acc_COMMON_INCLUDES_
#define GP_acc_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#define S_FUNCTION_NAME simulink_only_sfcn 
#define S_FUNCTION_LEVEL 2
#define RTW_GENERATED_S_FUNCTION
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "GP_acc_types.h"
typedef struct { real_T B_0_1_0 [ 6 ] ; real_T B_0_5_0 ; real_T B_0_6_0 [ 9 ]
; real_T B_0_9_0 [ 3 ] ; real_T B_0_15_0 [ 3 ] ; real_T B_0_41_0 [ 3 ] ;
real_T B_0_42_0 [ 3 ] ; real_T B_0_45_0 [ 3 ] ; real_T B_0_46_0 [ 3 ] ;
real_T B_0_47_0 [ 3 ] ; real_T B_0_56_0 [ 3 ] ; real_T B_0_84_0 ; real_T
B_0_85_0 [ 9 ] ; real_T B_0_88_0 [ 3 ] ; real_T B_0_92_0 [ 3 ] ; real_T
B_0_93_0 [ 3 ] ; real_T B_0_96_0 [ 3 ] ; real_T B_0_97_0 [ 3 ] ; real_T
B_0_110_0 [ 3 ] ; real_T B_0_111_0 [ 3 ] ; real_T B_0_113_0 [ 3 ] ; real_T
B_0_114_0 [ 4 ] ; real_T B_0_115_0 ; real_T B_0_116_0 ; real_T B_0_117_0 ;
real_T B_0_118_0 [ 3 ] ; real_T B_0_54_0 [ 4 ] ; real_T B_0_59_0 ; real_T
B_0_60_0 ; real_T B_0_62_0 [ 9 ] ; real_T B_0_72_0 [ 9 ] ; real_T B_0_77_0 [
3 ] ; real_T B_0_78_0 [ 3 ] ; real_T B_0_98_0 [ 3 ] ; real_T B_0_100_0 [ 3 ]
; real_T B_0_58_0 ; } B_GP_T ; typedef struct { real_T NextOutput [ 3 ] ;
real_T NextOutput_l [ 3 ] ; struct { real_T TimeStampA ; real_T LastUAtTimeA
[ 3 ] ; real_T TimeStampB ; real_T LastUAtTimeB [ 3 ] ; } Derivative_RWORK ;
struct { void * LoggedData ; } AComparsion_PWORK ; struct { void * LoggedData
; } Ab_PWORK ; struct { void * LoggedData ; } Ameg_PWORK ; struct { void *
LoggedData ; } Pqr_PWORK ; struct { void * LoggedData ; } PqrComparsion_PWORK
; struct { void * LoggedData ; } PhiThetaPsi_PWORK ; struct { void *
LoggedData ; } R_PWORK ; struct { void * LoggedData ; } Va_PWORK ; struct {
void * LoggedData ; } Vm_PWORK ; struct { void * LoggedData ; } Wmeg_PWORK ;
uint32_T RandSeed [ 3 ] ; uint32_T RandSeed_g [ 3 ] ; int_T Saturation_MODE [
3 ] ; int_T Saturation_MODE_m [ 3 ] ; } DW_GP_T ; typedef struct { real_T
TransferFcnX_CSTATE [ 2 ] ; real_T TransferFcnY_CSTATE [ 2 ] ; real_T
TransferFcnZ_CSTATE [ 2 ] ; real_T Integrator_CSTATE [ 4 ] ; real_T
Integrator_CSTATE_j [ 3 ] ; real_T Integrator_CSTATE_g ; real_T
Integrator2_CSTATE ; real_T Integrator3_CSTATE ; real_T Integrator1_CSTATE [
3 ] ; real_T TransferFcnX_CSTATE_g [ 2 ] ; real_T TransferFcnY_CSTATE_k [ 2 ]
; real_T TransferFcnZ_CSTATE_k [ 2 ] ; real_T Integrator_CSTATE_l [ 3 ] ;
real_T Integrator_CSTATE_i [ 3 ] ; } X_GP_T ; typedef struct { real_T
TransferFcnX_CSTATE [ 2 ] ; real_T TransferFcnY_CSTATE [ 2 ] ; real_T
TransferFcnZ_CSTATE [ 2 ] ; real_T Integrator_CSTATE [ 4 ] ; real_T
Integrator_CSTATE_j [ 3 ] ; real_T Integrator_CSTATE_g ; real_T
Integrator2_CSTATE ; real_T Integrator3_CSTATE ; real_T Integrator1_CSTATE [
3 ] ; real_T TransferFcnX_CSTATE_g [ 2 ] ; real_T TransferFcnY_CSTATE_k [ 2 ]
; real_T TransferFcnZ_CSTATE_k [ 2 ] ; real_T Integrator_CSTATE_l [ 3 ] ;
real_T Integrator_CSTATE_i [ 3 ] ; } XDot_GP_T ; typedef struct { boolean_T
TransferFcnX_CSTATE [ 2 ] ; boolean_T TransferFcnY_CSTATE [ 2 ] ; boolean_T
TransferFcnZ_CSTATE [ 2 ] ; boolean_T Integrator_CSTATE [ 4 ] ; boolean_T
Integrator_CSTATE_j [ 3 ] ; boolean_T Integrator_CSTATE_g ; boolean_T
Integrator2_CSTATE ; boolean_T Integrator3_CSTATE ; boolean_T
Integrator1_CSTATE [ 3 ] ; boolean_T TransferFcnX_CSTATE_g [ 2 ] ; boolean_T
TransferFcnY_CSTATE_k [ 2 ] ; boolean_T TransferFcnZ_CSTATE_k [ 2 ] ;
boolean_T Integrator_CSTATE_l [ 3 ] ; boolean_T Integrator_CSTATE_i [ 3 ] ; }
XDis_GP_T ; typedef struct { real_T TransferFcnX_CSTATE [ 2 ] ; real_T
TransferFcnY_CSTATE [ 2 ] ; real_T TransferFcnZ_CSTATE [ 2 ] ; real_T
Integrator_CSTATE [ 4 ] ; real_T Integrator_CSTATE_j [ 3 ] ; real_T
Integrator_CSTATE_g ; real_T Integrator2_CSTATE ; real_T Integrator3_CSTATE ;
real_T Integrator1_CSTATE [ 3 ] ; real_T TransferFcnX_CSTATE_g [ 2 ] ; real_T
TransferFcnY_CSTATE_k [ 2 ] ; real_T TransferFcnZ_CSTATE_k [ 2 ] ; real_T
Integrator_CSTATE_l [ 3 ] ; real_T Integrator_CSTATE_i [ 3 ] ; }
CStateAbsTol_GP_T ; typedef struct { real_T Saturation_UprLim_ZC [ 3 ] ;
real_T Saturation_LwrLim_ZC [ 3 ] ; real_T Saturation_UprLim_ZC_i [ 3 ] ;
real_T Saturation_LwrLim_ZC_o [ 3 ] ; } ZCV_GP_T ; typedef struct {
ZCSigState Saturation_UprLim_ZCE [ 3 ] ; ZCSigState Saturation_LwrLim_ZCE [ 3
] ; ZCSigState Saturation_UprLim_ZCE_f [ 3 ] ; ZCSigState
Saturation_LwrLim_ZCE_h [ 3 ] ; } PrevZCX_GP_T ; struct P_GP_T_ { real_T P_0
[ 3 ] ; real_T P_1 ; real_T P_2 ; real_T P_5 [ 3 ] ; real_T P_6 ; real_T P_7
; real_T P_10 [ 3 ] ; real_T P_11 ; real_T P_12 ; real_T P_15 ; real_T P_16 [
9 ] ; real_T P_17 ; real_T P_18 [ 3 ] ; real_T P_19 ; real_T P_20 ; real_T
P_21 [ 3 ] ; real_T P_22 ; real_T P_23 [ 3 ] ; real_T P_24 [ 3 ] ; real_T
P_25 ; real_T P_26 [ 3 ] ; real_T P_27 ; real_T P_28 ; real_T P_29 ; real_T
P_30 [ 3 ] ; real_T P_31 [ 3 ] ; real_T P_32 [ 3 ] ; real_T P_33 [ 3 ] ;
real_T P_34 [ 4 ] ; real_T P_35 [ 3 ] ; real_T P_36 ; real_T P_37 ; real_T
P_38 ; real_T P_39 ; real_T P_40 ; real_T P_41 [ 3 ] ; real_T P_42 ; real_T
P_43 ; real_T P_46 [ 3 ] ; real_T P_47 ; real_T P_48 ; real_T P_51 [ 3 ] ;
real_T P_52 ; real_T P_53 ; real_T P_56 ; real_T P_57 [ 9 ] ; real_T P_58 ;
real_T P_59 [ 3 ] ; real_T P_60 [ 3 ] ; real_T P_61 ; real_T P_62 [ 3 ] ;
real_T P_63 ; real_T P_64 ; real_T P_65 ; real_T P_66 [ 3 ] ; real_T P_67 [ 3
] ; real_T P_68 [ 3 ] ; real_T P_69 [ 3 ] ; real_T P_70 ; real_T P_71 [ 3 ] ;
real_T P_72 ; } ; extern P_GP_T GP_rtDefaultP ;
#endif
