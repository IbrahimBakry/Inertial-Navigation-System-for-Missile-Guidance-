#include "__cf_GP.h"
#include <math.h>
#include "GP_acc.h"
#include "GP_acc_private.h"
#include <stdio.h>
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T lo ; uint32_T
hi ; lo = * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if ( lo < hi
) { * u = 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; } return (
real_T ) * u * 4.6566128752457969E-10 ; } real_T rt_nrand_Upu32_Yd_f_pw_snf (
uint32_T * u ) { real_T y ; real_T sr ; real_T si ; do { sr = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } static void mdlOutputs ( SimStruct * S , int_T tid ) {
real_T B_0_2_0 ; real_T B_0_3_0 ; real_T B_0_4_0 ; real_T B_0_83_0 ; real_T
B_0_82_0 ; real_T B_0_81_0 ; real_T B_0_87_0 [ 3 ] ; real_T B_0_112_0 [ 3 ] ;
real_T tmp ; real_T tmp_0 ; int32_T i ; real_T B_0_7_0_idx ; real_T
B_0_7_0_idx_0 ; real_T B_0_7_0_idx_1 ; B_GP_T * _rtB ; P_GP_T * _rtP ;
DW_GP_T * _rtDW ; _rtDW = ( ( DW_GP_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( (
P_GP_T * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( B_GP_T * ) _ssGetBlockIO (
S ) ) ; ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_58_0 = ssGetT ( S ) ;
ssCallAccelRunBlock ( S , 0 , 1 , SS_CALL_MDL_OUTPUTS ) ; B_0_2_0 = _rtP ->
P_2 * ( ( X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnX_CSTATE [ 1 ] ;
B_0_3_0 = _rtP -> P_7 * ( ( X_GP_T * ) ssGetContStates ( S ) ) ->
TransferFcnY_CSTATE [ 1 ] ; B_0_4_0 = _rtP -> P_12 * ( ( X_GP_T * )
ssGetContStates ( S ) ) -> TransferFcnZ_CSTATE [ 1 ] ; if ( ssIsSampleHit ( S
, 1 , 0 ) ) { _rtB -> B_0_5_0 = _rtP -> P_15 ; memcpy ( & _rtB -> B_0_6_0 [ 0
] , & _rtP -> P_16 [ 0 ] , 9U * sizeof ( real_T ) ) ; } B_0_7_0_idx = _rtP ->
P_17 * _rtB -> B_0_1_0 [ 3 ] ; B_0_7_0_idx_0 = _rtP -> P_17 * _rtB -> B_0_1_0
[ 4 ] ; B_0_7_0_idx_1 = _rtP -> P_17 * _rtB -> B_0_1_0 [ 5 ] ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_0_9_0 [ 0 ] = _rtP -> P_19 * _rtP
-> P_18 [ 0 ] ; _rtB -> B_0_9_0 [ 1 ] = _rtP -> P_19 * _rtP -> P_18 [ 1 ] ;
_rtB -> B_0_9_0 [ 2 ] = _rtP -> P_19 * _rtP -> P_18 [ 2 ] ; } B_0_87_0 [ 0 ]
= _rtP -> P_20 * _rtB -> B_0_1_0 [ 0 ] ; B_0_87_0 [ 1 ] = _rtP -> P_20 * _rtB
-> B_0_1_0 [ 1 ] ; B_0_87_0 [ 2 ] = _rtP -> P_20 * _rtB -> B_0_1_0 [ 2 ] ; if
( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_0_15_0 [ 0 ] = ( _rtP -> P_22 *
_rtP -> P_21 [ 0 ] - _rtP -> P_23 [ 0 ] ) * _rtP -> P_24 [ 0 ] ; _rtB ->
B_0_15_0 [ 1 ] = ( _rtP -> P_22 * _rtP -> P_21 [ 1 ] - _rtP -> P_23 [ 1 ] ) *
_rtP -> P_24 [ 1 ] ; _rtB -> B_0_15_0 [ 2 ] = ( _rtP -> P_22 * _rtP -> P_21 [
2 ] - _rtP -> P_23 [ 2 ] ) * _rtP -> P_24 [ 2 ] ; } B_0_83_0 = B_0_87_0 [ 2 ]
* _rtB -> B_0_15_0 [ 1 ] ; B_0_82_0 = B_0_87_0 [ 0 ] * _rtB -> B_0_15_0 [ 2 ]
; B_0_81_0 = B_0_87_0 [ 1 ] * _rtB -> B_0_15_0 [ 0 ] ; B_0_112_0 [ 0 ] =
B_0_87_0 [ 1 ] * _rtB -> B_0_15_0 [ 2 ] - B_0_83_0 ; B_0_112_0 [ 1 ] =
B_0_87_0 [ 2 ] * _rtB -> B_0_15_0 [ 0 ] - B_0_82_0 ; B_0_112_0 [ 2 ] =
B_0_87_0 [ 0 ] * _rtB -> B_0_15_0 [ 1 ] - B_0_81_0 ; B_0_81_0 = B_0_87_0 [ 1
] * B_0_112_0 [ 2 ] ; B_0_82_0 = B_0_87_0 [ 2 ] * B_0_112_0 [ 0 ] ; B_0_83_0
= B_0_87_0 [ 0 ] * B_0_112_0 [ 1 ] ; tmp = B_0_112_0 [ 2 ] ; tmp_0 =
B_0_112_0 [ 0 ] ; B_0_112_0 [ 0 ] = B_0_81_0 - B_0_87_0 [ 2 ] * B_0_112_0 [ 1
] ; B_0_112_0 [ 1 ] = B_0_82_0 - B_0_87_0 [ 0 ] * tmp ; B_0_112_0 [ 2 ] =
B_0_83_0 - B_0_87_0 [ 1 ] * tmp_0 ; { real_T t = ssGetTaskTime ( S , 0 ) ;
real_T timeStampA = _rtDW -> Derivative_RWORK . TimeStampA ; real_T
timeStampB = _rtDW -> Derivative_RWORK . TimeStampB ; real_T * lastU = &
_rtDW -> Derivative_RWORK . LastUAtTimeA [ 0 ] ; if ( timeStampA >= t &&
timeStampB >= t ) { B_0_87_0 [ 0 ] = 0.0 ; B_0_87_0 [ 1 ] = 0.0 ; B_0_87_0 [
2 ] = 0.0 ; } else { real_T deltaT ; real_T lastTime = timeStampA ; if (
timeStampA < timeStampB ) { if ( timeStampB < t ) { lastTime = timeStampB ;
lastU = & _rtDW -> Derivative_RWORK . LastUAtTimeB [ 0 ] ; } } else if (
timeStampA >= t ) { lastTime = timeStampB ; lastU = & _rtDW ->
Derivative_RWORK . LastUAtTimeB [ 0 ] ; } deltaT = t - lastTime ; B_0_87_0 [
0 ] = ( ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_1_0 [ 0 ] - * lastU ++ )
/ deltaT ; B_0_87_0 [ 1 ] = ( ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_1_0
[ 1 ] - * lastU ++ ) / deltaT ; B_0_87_0 [ 2 ] = ( ( ( B_GP_T * )
_ssGetBlockIO ( S ) ) -> B_0_1_0 [ 2 ] - * lastU ++ ) / deltaT ; } } B_0_87_0
[ 0 ] *= _rtP -> P_25 ; B_0_87_0 [ 1 ] *= _rtP -> P_25 ; B_0_87_0 [ 2 ] *=
_rtP -> P_25 ; B_0_81_0 = B_0_87_0 [ 1 ] * _rtB -> B_0_15_0 [ 2 ] ; B_0_82_0
= B_0_87_0 [ 2 ] * _rtB -> B_0_15_0 [ 0 ] ; B_0_83_0 = B_0_87_0 [ 0 ] * _rtB
-> B_0_15_0 [ 1 ] ; tmp = B_0_87_0 [ 0 ] ; tmp_0 = B_0_87_0 [ 1 ] ; B_0_87_0
[ 0 ] = B_0_81_0 - B_0_87_0 [ 2 ] * _rtB -> B_0_15_0 [ 1 ] ; B_0_87_0 [ 1 ] =
B_0_82_0 - tmp * _rtB -> B_0_15_0 [ 2 ] ; B_0_87_0 [ 2 ] = B_0_83_0 - tmp_0 *
_rtB -> B_0_15_0 [ 0 ] ; B_0_112_0 [ 0 ] = ( ( B_0_7_0_idx - _rtB -> B_0_9_0
[ 0 ] ) + B_0_112_0 [ 0 ] ) + B_0_87_0 [ 0 ] ; B_0_112_0 [ 1 ] = ( (
B_0_7_0_idx_0 - _rtB -> B_0_9_0 [ 1 ] ) + B_0_112_0 [ 1 ] ) + B_0_87_0 [ 1 ]
; B_0_112_0 [ 2 ] = ( ( B_0_7_0_idx_1 - _rtB -> B_0_9_0 [ 2 ] ) + B_0_112_0 [
2 ] ) + B_0_87_0 [ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { B_0_87_0 [ i ] = 0.0
; B_0_87_0 [ i ] += _rtB -> B_0_6_0 [ i ] * B_0_112_0 [ 0 ] ; B_0_87_0 [ i ]
+= _rtB -> B_0_6_0 [ i + 3 ] * B_0_112_0 [ 1 ] ; B_0_87_0 [ i ] += _rtB ->
B_0_6_0 [ i + 6 ] * B_0_112_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) {
_rtB -> B_0_41_0 [ 0 ] = _rtP -> P_26 [ 0 ] ; _rtB -> B_0_41_0 [ 1 ] = _rtP
-> P_26 [ 1 ] ; _rtB -> B_0_41_0 [ 2 ] = _rtP -> P_26 [ 2 ] ; } _rtB ->
B_0_42_0 [ 0 ] = B_0_87_0 [ 0 ] + _rtB -> B_0_41_0 [ 0 ] ; _rtB -> B_0_42_0 [
1 ] = B_0_87_0 [ 1 ] + _rtB -> B_0_41_0 [ 1 ] ; _rtB -> B_0_42_0 [ 2 ] =
B_0_87_0 [ 2 ] + _rtB -> B_0_41_0 [ 2 ] ; if ( _rtB -> B_0_5_0 >= _rtP ->
P_27 ) { B_0_112_0 [ 0 ] = B_0_2_0 ; } else { B_0_112_0 [ 0 ] = _rtB ->
B_0_42_0 [ 0 ] ; } if ( _rtB -> B_0_5_0 >= _rtP -> P_27 ) { B_0_112_0 [ 1 ] =
B_0_3_0 ; } else { B_0_112_0 [ 1 ] = _rtB -> B_0_42_0 [ 1 ] ; } if ( _rtB ->
B_0_5_0 >= _rtP -> P_27 ) { B_0_112_0 [ 2 ] = B_0_4_0 ; } else { B_0_112_0 [
2 ] = _rtB -> B_0_42_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 2 , 0 ) ) { _rtB ->
B_0_45_0 [ 0 ] = _rtP -> P_31 [ 0 ] * _rtDW -> NextOutput [ 0 ] ; _rtB ->
B_0_45_0 [ 1 ] = _rtP -> P_31 [ 1 ] * _rtDW -> NextOutput [ 1 ] ; _rtB ->
B_0_45_0 [ 2 ] = _rtP -> P_31 [ 2 ] * _rtDW -> NextOutput [ 2 ] ; } _rtB ->
B_0_46_0 [ 0 ] = B_0_112_0 [ 0 ] + _rtB -> B_0_45_0 [ 0 ] ; _rtB -> B_0_46_0
[ 1 ] = B_0_112_0 [ 1 ] + _rtB -> B_0_45_0 [ 1 ] ; _rtB -> B_0_46_0 [ 2 ] =
B_0_112_0 [ 2 ] + _rtB -> B_0_45_0 [ 2 ] ; if ( ssIsMajorTimeStep ( S ) ) {
_rtDW -> Saturation_MODE [ 0 ] = _rtB -> B_0_46_0 [ 0 ] >= _rtP -> P_32 [ 0 ]
? 1 : _rtB -> B_0_46_0 [ 0 ] > _rtP -> P_33 [ 0 ] ? 0 : - 1 ; _rtDW ->
Saturation_MODE [ 1 ] = _rtB -> B_0_46_0 [ 1 ] >= _rtP -> P_32 [ 1 ] ? 1 :
_rtB -> B_0_46_0 [ 1 ] > _rtP -> P_33 [ 1 ] ? 0 : - 1 ; _rtDW ->
Saturation_MODE [ 2 ] = _rtB -> B_0_46_0 [ 2 ] >= _rtP -> P_32 [ 2 ] ? 1 :
_rtB -> B_0_46_0 [ 2 ] > _rtP -> P_33 [ 2 ] ? 0 : - 1 ; } _rtB -> B_0_47_0 [
0 ] = _rtDW -> Saturation_MODE [ 0 ] == 1 ? _rtP -> P_32 [ 0 ] : _rtDW ->
Saturation_MODE [ 0 ] == - 1 ? _rtP -> P_33 [ 0 ] : _rtB -> B_0_46_0 [ 0 ] ;
_rtB -> B_0_47_0 [ 1 ] = _rtDW -> Saturation_MODE [ 1 ] == 1 ? _rtP -> P_32 [
1 ] : _rtDW -> Saturation_MODE [ 1 ] == - 1 ? _rtP -> P_33 [ 1 ] : _rtB ->
B_0_46_0 [ 1 ] ; _rtB -> B_0_47_0 [ 2 ] = _rtDW -> Saturation_MODE [ 2 ] == 1
? _rtP -> P_32 [ 2 ] : _rtDW -> Saturation_MODE [ 2 ] == - 1 ? _rtP -> P_33 [
2 ] : _rtB -> B_0_46_0 [ 2 ] ; ssCallAccelRunBlock ( S , 0 , 48 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 49 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 50 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 51 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 52 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 0 , 53 ,
SS_CALL_MDL_OUTPUTS ) ; ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_54_0 [ 0
] = ( ( X_GP_T * ) ssGetContStates ( S ) ) -> Integrator_CSTATE [ 0 ] ; ( (
B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_54_0 [ 1 ] = ( ( X_GP_T * )
ssGetContStates ( S ) ) -> Integrator_CSTATE [ 1 ] ; ( ( B_GP_T * )
_ssGetBlockIO ( S ) ) -> B_0_54_0 [ 2 ] = ( ( X_GP_T * ) ssGetContStates ( S
) ) -> Integrator_CSTATE [ 2 ] ; ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) ->
B_0_54_0 [ 3 ] = ( ( X_GP_T * ) ssGetContStates ( S ) ) -> Integrator_CSTATE
[ 3 ] ; ssCallAccelRunBlock ( S , 0 , 55 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_0_56_0 [ 0 ] = _rtP -> P_35 [ 0 ] ;
_rtB -> B_0_56_0 [ 1 ] = _rtP -> P_35 [ 1 ] ; _rtB -> B_0_56_0 [ 2 ] = _rtP
-> P_35 [ 2 ] ; } B_0_112_0 [ 0 ] = ( ( X_GP_T * ) ssGetContStates ( S ) ) ->
Integrator_CSTATE_j [ 0 ] ; B_0_112_0 [ 1 ] = ( ( X_GP_T * ) ssGetContStates
( S ) ) -> Integrator_CSTATE_j [ 1 ] ; B_0_112_0 [ 2 ] = ( ( X_GP_T * )
ssGetContStates ( S ) ) -> Integrator_CSTATE_j [ 2 ] ; _rtB -> B_0_58_0 =
_rtB -> B_0_56_0 [ 0 ] + B_0_112_0 [ 0 ] ; _rtB -> B_0_59_0 = _rtB ->
B_0_56_0 [ 1 ] + B_0_112_0 [ 1 ] ; _rtB -> B_0_60_0 = _rtB -> B_0_56_0 [ 2 ]
+ B_0_112_0 [ 2 ] ; ssCallAccelRunBlock ( S , 0 , 61 , SS_CALL_MDL_OUTPUTS )
; ssCallAccelRunBlock ( S , 0 , 62 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_0_72_0
[ 0 ] = _rtB -> B_0_62_0 [ 0 ] ; _rtB -> B_0_72_0 [ 1 ] = _rtB -> B_0_62_0 [
3 ] ; _rtB -> B_0_72_0 [ 2 ] = _rtB -> B_0_62_0 [ 6 ] ; _rtB -> B_0_72_0 [ 3
] = _rtB -> B_0_62_0 [ 1 ] ; _rtB -> B_0_72_0 [ 4 ] = _rtB -> B_0_62_0 [ 4 ]
; _rtB -> B_0_72_0 [ 5 ] = _rtB -> B_0_62_0 [ 7 ] ; _rtB -> B_0_72_0 [ 6 ] =
_rtB -> B_0_62_0 [ 2 ] ; _rtB -> B_0_72_0 [ 7 ] = _rtB -> B_0_62_0 [ 5 ] ;
_rtB -> B_0_72_0 [ 8 ] = _rtB -> B_0_62_0 [ 8 ] ; B_0_81_0 = ( ( X_GP_T * )
ssGetContStates ( S ) ) -> Integrator_CSTATE_g ; B_0_82_0 = ( ( X_GP_T * )
ssGetContStates ( S ) ) -> Integrator2_CSTATE ; B_0_83_0 = ( ( X_GP_T * )
ssGetContStates ( S ) ) -> Integrator3_CSTATE ; B_0_112_0 [ 0 ] = ( ( X_GP_T
* ) ssGetContStates ( S ) ) -> Integrator1_CSTATE [ 0 ] ; B_0_112_0 [ 1 ] = (
( X_GP_T * ) ssGetContStates ( S ) ) -> Integrator1_CSTATE [ 1 ] ; B_0_112_0
[ 2 ] = ( ( X_GP_T * ) ssGetContStates ( S ) ) -> Integrator1_CSTATE [ 2 ] ;
_rtB -> B_0_77_0 [ 0 ] = B_0_81_0 + B_0_112_0 [ 0 ] ; _rtB -> B_0_77_0 [ 1 ]
= B_0_82_0 + B_0_112_0 [ 1 ] ; _rtB -> B_0_77_0 [ 2 ] = B_0_83_0 + B_0_112_0
[ 2 ] ; for ( i = 0 ; i < 3 ; i ++ ) { _rtB -> B_0_78_0 [ i ] = 0.0 ; _rtB ->
B_0_78_0 [ i ] += _rtB -> B_0_72_0 [ i ] * _rtB -> B_0_77_0 [ 0 ] ; _rtB ->
B_0_78_0 [ i ] += _rtB -> B_0_72_0 [ i + 3 ] * _rtB -> B_0_77_0 [ 1 ] ; _rtB
-> B_0_78_0 [ i ] += _rtB -> B_0_72_0 [ i + 6 ] * _rtB -> B_0_77_0 [ 2 ] ; }
ssCallAccelRunBlock ( S , 0 , 79 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 80 , SS_CALL_MDL_OUTPUTS ) ; B_0_81_0 = _rtP ->
P_43 * ( ( X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnX_CSTATE_g [ 1 ]
; B_0_82_0 = _rtP -> P_48 * ( ( X_GP_T * ) ssGetContStates ( S ) ) ->
TransferFcnY_CSTATE_k [ 1 ] ; B_0_83_0 = _rtP -> P_53 * ( ( X_GP_T * )
ssGetContStates ( S ) ) -> TransferFcnZ_CSTATE_k [ 1 ] ; if ( ssIsSampleHit (
S , 1 , 0 ) ) { _rtB -> B_0_84_0 = _rtP -> P_56 ; memcpy ( & _rtB -> B_0_85_0
[ 0 ] , & _rtP -> P_57 [ 0 ] , 9U * sizeof ( real_T ) ) ; } B_0_112_0 [ 0 ] =
_rtP -> P_58 * _rtB -> B_0_1_0 [ 0 ] ; B_0_112_0 [ 1 ] = _rtP -> P_58 * _rtB
-> B_0_1_0 [ 1 ] ; B_0_112_0 [ 2 ] = _rtP -> P_58 * _rtB -> B_0_1_0 [ 2 ] ;
for ( i = 0 ; i < 3 ; i ++ ) { B_0_87_0 [ i ] = 0.0 ; B_0_87_0 [ i ] += _rtB
-> B_0_85_0 [ i ] * B_0_112_0 [ 0 ] ; B_0_87_0 [ i ] += _rtB -> B_0_85_0 [ i
+ 3 ] * B_0_112_0 [ 1 ] ; B_0_87_0 [ i ] += _rtB -> B_0_85_0 [ i + 6 ] *
B_0_112_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_0_88_0 [ 0
] = _rtP -> P_59 [ 0 ] ; _rtB -> B_0_88_0 [ 1 ] = _rtP -> P_59 [ 1 ] ; _rtB
-> B_0_88_0 [ 2 ] = _rtP -> P_59 [ 2 ] ; _rtB -> B_0_92_0 [ 0 ] = _rtP ->
P_61 * _rtP -> P_60 [ 0 ] * _rtP -> P_62 [ 0 ] ; _rtB -> B_0_92_0 [ 1 ] =
_rtP -> P_61 * _rtP -> P_60 [ 1 ] * _rtP -> P_62 [ 1 ] ; _rtB -> B_0_92_0 [ 2
] = _rtP -> P_61 * _rtP -> P_60 [ 2 ] * _rtP -> P_62 [ 2 ] ; } _rtB ->
B_0_93_0 [ 0 ] = ( B_0_87_0 [ 0 ] + _rtB -> B_0_88_0 [ 0 ] ) + _rtB ->
B_0_92_0 [ 0 ] ; _rtB -> B_0_93_0 [ 1 ] = ( B_0_87_0 [ 1 ] + _rtB -> B_0_88_0
[ 1 ] ) + _rtB -> B_0_92_0 [ 1 ] ; _rtB -> B_0_93_0 [ 2 ] = ( B_0_87_0 [ 2 ]
+ _rtB -> B_0_88_0 [ 2 ] ) + _rtB -> B_0_92_0 [ 2 ] ; if ( _rtB -> B_0_84_0
>= _rtP -> P_63 ) { B_0_112_0 [ 0 ] = B_0_81_0 ; } else { B_0_112_0 [ 0 ] =
_rtB -> B_0_93_0 [ 0 ] ; } if ( _rtB -> B_0_84_0 >= _rtP -> P_63 ) {
B_0_112_0 [ 1 ] = B_0_82_0 ; } else { B_0_112_0 [ 1 ] = _rtB -> B_0_93_0 [ 1
] ; } if ( _rtB -> B_0_84_0 >= _rtP -> P_63 ) { B_0_112_0 [ 2 ] = B_0_83_0 ;
} else { B_0_112_0 [ 2 ] = _rtB -> B_0_93_0 [ 2 ] ; } if ( ssIsSampleHit ( S
, 2 , 0 ) ) { _rtB -> B_0_96_0 [ 0 ] = _rtP -> P_67 [ 0 ] * _rtDW ->
NextOutput_l [ 0 ] ; _rtB -> B_0_96_0 [ 1 ] = _rtP -> P_67 [ 1 ] * _rtDW ->
NextOutput_l [ 1 ] ; _rtB -> B_0_96_0 [ 2 ] = _rtP -> P_67 [ 2 ] * _rtDW ->
NextOutput_l [ 2 ] ; } _rtB -> B_0_97_0 [ 0 ] = B_0_112_0 [ 0 ] + _rtB ->
B_0_96_0 [ 0 ] ; _rtB -> B_0_97_0 [ 1 ] = B_0_112_0 [ 1 ] + _rtB -> B_0_96_0
[ 1 ] ; _rtB -> B_0_97_0 [ 2 ] = B_0_112_0 [ 2 ] + _rtB -> B_0_96_0 [ 2 ] ;
if ( ssIsMajorTimeStep ( S ) ) { _rtDW -> Saturation_MODE_m [ 0 ] = _rtB ->
B_0_97_0 [ 0 ] >= _rtP -> P_68 [ 0 ] ? 1 : _rtB -> B_0_97_0 [ 0 ] > _rtP ->
P_69 [ 0 ] ? 0 : - 1 ; _rtDW -> Saturation_MODE_m [ 1 ] = _rtB -> B_0_97_0 [
1 ] >= _rtP -> P_68 [ 1 ] ? 1 : _rtB -> B_0_97_0 [ 1 ] > _rtP -> P_69 [ 1 ] ?
0 : - 1 ; _rtDW -> Saturation_MODE_m [ 2 ] = _rtB -> B_0_97_0 [ 2 ] >= _rtP
-> P_68 [ 2 ] ? 1 : _rtB -> B_0_97_0 [ 2 ] > _rtP -> P_69 [ 2 ] ? 0 : - 1 ; }
_rtB -> B_0_98_0 [ 0 ] = _rtDW -> Saturation_MODE_m [ 0 ] == 1 ? _rtP -> P_68
[ 0 ] : _rtDW -> Saturation_MODE_m [ 0 ] == - 1 ? _rtP -> P_69 [ 0 ] : _rtB
-> B_0_97_0 [ 0 ] ; _rtB -> B_0_98_0 [ 1 ] = _rtDW -> Saturation_MODE_m [ 1 ]
== 1 ? _rtP -> P_68 [ 1 ] : _rtDW -> Saturation_MODE_m [ 1 ] == - 1 ? _rtP ->
P_69 [ 1 ] : _rtB -> B_0_97_0 [ 1 ] ; _rtB -> B_0_98_0 [ 2 ] = _rtDW ->
Saturation_MODE_m [ 2 ] == 1 ? _rtP -> P_68 [ 2 ] : _rtDW ->
Saturation_MODE_m [ 2 ] == - 1 ? _rtP -> P_69 [ 2 ] : _rtB -> B_0_97_0 [ 2 ]
; ssCallAccelRunBlock ( S , 0 , 99 , SS_CALL_MDL_OUTPUTS ) ; ( ( B_GP_T * )
_ssGetBlockIO ( S ) ) -> B_0_100_0 [ 0 ] = ( ( X_GP_T * ) ssGetContStates ( S
) ) -> Integrator_CSTATE_l [ 0 ] ; ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) ->
B_0_100_0 [ 1 ] = ( ( X_GP_T * ) ssGetContStates ( S ) ) ->
Integrator_CSTATE_l [ 1 ] ; ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_100_0
[ 2 ] = ( ( X_GP_T * ) ssGetContStates ( S ) ) -> Integrator_CSTATE_l [ 2 ] ;
ssCallAccelRunBlock ( S , 0 , 101 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 102 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 103 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 104 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 105 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 106 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 107 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 108 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 109 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 0 , 110 , SS_CALL_MDL_OUTPUTS ) ; if (
ssIsSampleHit ( S , 1 , 0 ) ) { _rtB -> B_0_111_0 [ 0 ] = _rtP -> P_71 [ 0 ]
; _rtB -> B_0_111_0 [ 1 ] = _rtP -> P_71 [ 1 ] ; _rtB -> B_0_111_0 [ 2 ] =
_rtP -> P_71 [ 2 ] ; } B_0_112_0 [ 0 ] = ( ( X_GP_T * ) ssGetContStates ( S )
) -> Integrator_CSTATE_i [ 0 ] ; B_0_112_0 [ 1 ] = ( ( X_GP_T * )
ssGetContStates ( S ) ) -> Integrator_CSTATE_i [ 1 ] ; B_0_112_0 [ 2 ] = ( (
X_GP_T * ) ssGetContStates ( S ) ) -> Integrator_CSTATE_i [ 2 ] ; for ( i = 0
; i < 3 ; i ++ ) { _rtB -> B_0_113_0 [ i ] = 0.0 ; _rtB -> B_0_113_0 [ i ] +=
_rtB -> B_0_72_0 [ i ] * _rtB -> B_0_98_0 [ 0 ] ; _rtB -> B_0_113_0 [ i ] +=
_rtB -> B_0_72_0 [ i + 3 ] * _rtB -> B_0_98_0 [ 1 ] ; _rtB -> B_0_113_0 [ i ]
+= _rtB -> B_0_72_0 [ i + 6 ] * _rtB -> B_0_98_0 [ 2 ] ; }
ssCallAccelRunBlock ( S , 0 , 114 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_0_115_0
= ( _rtB -> B_0_111_0 [ 2 ] + _rtB -> B_0_78_0 [ 2 ] ) + B_0_112_0 [ 2 ] ;
_rtB -> B_0_116_0 = ( _rtB -> B_0_111_0 [ 1 ] + _rtB -> B_0_78_0 [ 1 ] ) +
B_0_112_0 [ 1 ] ; _rtB -> B_0_117_0 = ( _rtB -> B_0_111_0 [ 0 ] + _rtB ->
B_0_78_0 [ 0 ] ) + B_0_112_0 [ 0 ] ; _rtB -> B_0_118_0 [ 0 ] = _rtB ->
B_0_98_0 [ 0 ] * _rtB -> B_0_77_0 [ 0 ] ; _rtB -> B_0_118_0 [ 1 ] = _rtB ->
B_0_98_0 [ 1 ] * _rtB -> B_0_77_0 [ 1 ] ; _rtB -> B_0_118_0 [ 2 ] = _rtB ->
B_0_98_0 [ 2 ] * _rtB -> B_0_77_0 [ 2 ] ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_GP_T * _rtB ; P_GP_T
* _rtP ; DW_GP_T * _rtDW ; _rtDW = ( ( DW_GP_T * ) ssGetRootDWork ( S ) ) ;
_rtP = ( ( P_GP_T * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( B_GP_T * )
_ssGetBlockIO ( S ) ) ; { real_T timeStampA = _rtDW -> Derivative_RWORK .
TimeStampA ; real_T timeStampB = _rtDW -> Derivative_RWORK . TimeStampB ;
real_T * lastTime = & _rtDW -> Derivative_RWORK . TimeStampA ; real_T * lastU
= & _rtDW -> Derivative_RWORK . LastUAtTimeA [ 0 ] ; if ( timeStampA != rtInf
) { if ( timeStampB == rtInf ) { lastTime = & _rtDW -> Derivative_RWORK .
TimeStampB ; lastU = & _rtDW -> Derivative_RWORK . LastUAtTimeB [ 0 ] ; }
else if ( timeStampA >= timeStampB ) { lastTime = & _rtDW -> Derivative_RWORK
. TimeStampB ; lastU = & _rtDW -> Derivative_RWORK . LastUAtTimeB [ 0 ] ; } }
* lastTime = ssGetTaskTime ( S , 0 ) ; * lastU ++ = ( ( B_GP_T * )
_ssGetBlockIO ( S ) ) -> B_0_1_0 [ 0 ] ; * lastU ++ = ( ( B_GP_T * )
_ssGetBlockIO ( S ) ) -> B_0_1_0 [ 1 ] ; * lastU ++ = ( ( B_GP_T * )
_ssGetBlockIO ( S ) ) -> B_0_1_0 [ 2 ] ; } if ( ssIsSampleHit ( S , 2 , 0 ) )
{ _rtDW -> NextOutput [ 0 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
RandSeed [ 0 ] ) * _rtP -> P_29 + _rtP -> P_28 ; _rtDW -> NextOutput [ 1 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed [ 1 ] ) * _rtP -> P_29 +
_rtP -> P_28 ; _rtDW -> NextOutput [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( &
_rtDW -> RandSeed [ 2 ] ) * _rtP -> P_29 + _rtP -> P_28 ; } if (
ssIsSampleHit ( S , 2 , 0 ) ) { _rtDW -> NextOutput_l [ 0 ] =
rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_g [ 0 ] ) * _rtP -> P_65 +
_rtP -> P_64 ; _rtDW -> NextOutput_l [ 1 ] = rt_nrand_Upu32_Yd_f_pw_snf ( &
_rtDW -> RandSeed_g [ 1 ] ) * _rtP -> P_65 + _rtP -> P_64 ; _rtDW ->
NextOutput_l [ 2 ] = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_g [ 2 ]
) * _rtP -> P_65 + _rtP -> P_64 ; } UNUSED_PARAMETER ( tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_GP_T * _rtB ; P_GP_T * _rtP
; _rtP = ( ( P_GP_T * ) ssGetDefaultParam ( S ) ) ; _rtB = ( ( B_GP_T * )
_ssGetBlockIO ( S ) ) ; { ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
TransferFcnX_CSTATE [ 0 ] = ( _rtP -> P_0 [ 0 ] ) * ( ( X_GP_T * )
ssGetContStates ( S ) ) -> TransferFcnX_CSTATE [ 0 ] + ( _rtP -> P_0 [ 1 ] )
* ( ( X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnX_CSTATE [ 1 ] ; ( (
XDot_GP_T * ) ssGetdX ( S ) ) -> TransferFcnX_CSTATE [ 0 ] += _rtP -> P_1 * (
( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_42_0 [ 0 ] ; ( ( XDot_GP_T * )
ssGetdX ( S ) ) -> TransferFcnX_CSTATE [ 1 ] = ( _rtP -> P_0 [ 2 ] ) * ( (
X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnX_CSTATE [ 0 ] ; } { ( (
XDot_GP_T * ) ssGetdX ( S ) ) -> TransferFcnY_CSTATE [ 0 ] = ( _rtP -> P_5 [
0 ] ) * ( ( X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnY_CSTATE [ 0 ] +
( _rtP -> P_5 [ 1 ] ) * ( ( X_GP_T * ) ssGetContStates ( S ) ) ->
TransferFcnY_CSTATE [ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
TransferFcnY_CSTATE [ 0 ] += _rtP -> P_6 * ( ( B_GP_T * ) _ssGetBlockIO ( S )
) -> B_0_42_0 [ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
TransferFcnY_CSTATE [ 1 ] = ( _rtP -> P_5 [ 2 ] ) * ( ( X_GP_T * )
ssGetContStates ( S ) ) -> TransferFcnY_CSTATE [ 0 ] ; } { ( ( XDot_GP_T * )
ssGetdX ( S ) ) -> TransferFcnZ_CSTATE [ 0 ] = ( _rtP -> P_10 [ 0 ] ) * ( (
X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnZ_CSTATE [ 0 ] + ( _rtP ->
P_10 [ 1 ] ) * ( ( X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnZ_CSTATE
[ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) -> TransferFcnZ_CSTATE [ 0 ] +=
_rtP -> P_11 * ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_42_0 [ 2 ] ; ( (
XDot_GP_T * ) ssGetdX ( S ) ) -> TransferFcnZ_CSTATE [ 1 ] = ( _rtP -> P_10 [
2 ] ) * ( ( X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnZ_CSTATE [ 0 ] ;
} { ( ( XDot_GP_T * ) ssGetdX ( S ) ) -> Integrator_CSTATE [ 0 ] = ( ( B_GP_T
* ) _ssGetBlockIO ( S ) ) -> B_0_114_0 [ 0 ] ; ( ( XDot_GP_T * ) ssGetdX ( S
) ) -> Integrator_CSTATE [ 1 ] = ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) ->
B_0_114_0 [ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) -> Integrator_CSTATE [ 2
] = ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_114_0 [ 2 ] ; ( ( XDot_GP_T *
) ssGetdX ( S ) ) -> Integrator_CSTATE [ 3 ] = ( ( B_GP_T * ) _ssGetBlockIO (
S ) ) -> B_0_114_0 [ 3 ] ; } { ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
Integrator_CSTATE_j [ 0 ] = ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_117_0
; ( ( XDot_GP_T * ) ssGetdX ( S ) ) -> Integrator_CSTATE_j [ 1 ] = ( ( B_GP_T
* ) _ssGetBlockIO ( S ) ) -> B_0_116_0 ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
Integrator_CSTATE_j [ 2 ] = ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_115_0
; } { ( ( XDot_GP_T * ) ssGetdX ( S ) ) -> Integrator_CSTATE_g = ( ( B_GP_T *
) _ssGetBlockIO ( S ) ) -> B_0_47_0 [ 0 ] ; } { ( ( XDot_GP_T * ) ssGetdX ( S
) ) -> Integrator2_CSTATE = ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_47_0
[ 1 ] ; } { ( ( XDot_GP_T * ) ssGetdX ( S ) ) -> Integrator3_CSTATE = ( (
B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_47_0 [ 2 ] ; } { ( ( XDot_GP_T * )
ssGetdX ( S ) ) -> Integrator1_CSTATE [ 0 ] = ( ( B_GP_T * ) _ssGetBlockIO (
S ) ) -> B_0_118_0 [ 0 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
Integrator1_CSTATE [ 1 ] = ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_118_0
[ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) -> Integrator1_CSTATE [ 2 ] = ( (
B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_118_0 [ 2 ] ; } { ( ( XDot_GP_T * )
ssGetdX ( S ) ) -> TransferFcnX_CSTATE_g [ 0 ] = ( _rtP -> P_41 [ 0 ] ) * ( (
X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnX_CSTATE_g [ 0 ] + ( _rtP ->
P_41 [ 1 ] ) * ( ( X_GP_T * ) ssGetContStates ( S ) ) ->
TransferFcnX_CSTATE_g [ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
TransferFcnX_CSTATE_g [ 0 ] += _rtP -> P_42 * ( ( B_GP_T * ) _ssGetBlockIO (
S ) ) -> B_0_93_0 [ 0 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
TransferFcnX_CSTATE_g [ 1 ] = ( _rtP -> P_41 [ 2 ] ) * ( ( X_GP_T * )
ssGetContStates ( S ) ) -> TransferFcnX_CSTATE_g [ 0 ] ; } { ( ( XDot_GP_T *
) ssGetdX ( S ) ) -> TransferFcnY_CSTATE_k [ 0 ] = ( _rtP -> P_46 [ 0 ] ) * (
( X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnY_CSTATE_k [ 0 ] + ( _rtP
-> P_46 [ 1 ] ) * ( ( X_GP_T * ) ssGetContStates ( S ) ) ->
TransferFcnY_CSTATE_k [ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
TransferFcnY_CSTATE_k [ 0 ] += _rtP -> P_47 * ( ( B_GP_T * ) _ssGetBlockIO (
S ) ) -> B_0_93_0 [ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
TransferFcnY_CSTATE_k [ 1 ] = ( _rtP -> P_46 [ 2 ] ) * ( ( X_GP_T * )
ssGetContStates ( S ) ) -> TransferFcnY_CSTATE_k [ 0 ] ; } { ( ( XDot_GP_T *
) ssGetdX ( S ) ) -> TransferFcnZ_CSTATE_k [ 0 ] = ( _rtP -> P_51 [ 0 ] ) * (
( X_GP_T * ) ssGetContStates ( S ) ) -> TransferFcnZ_CSTATE_k [ 0 ] + ( _rtP
-> P_51 [ 1 ] ) * ( ( X_GP_T * ) ssGetContStates ( S ) ) ->
TransferFcnZ_CSTATE_k [ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
TransferFcnZ_CSTATE_k [ 0 ] += _rtP -> P_52 * ( ( B_GP_T * ) _ssGetBlockIO (
S ) ) -> B_0_93_0 [ 2 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
TransferFcnZ_CSTATE_k [ 1 ] = ( _rtP -> P_51 [ 2 ] ) * ( ( X_GP_T * )
ssGetContStates ( S ) ) -> TransferFcnZ_CSTATE_k [ 0 ] ; } { ( ( XDot_GP_T *
) ssGetdX ( S ) ) -> Integrator_CSTATE_l [ 0 ] = ( ( B_GP_T * ) _ssGetBlockIO
( S ) ) -> B_0_113_0 [ 0 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
Integrator_CSTATE_l [ 1 ] = ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_113_0
[ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) -> Integrator_CSTATE_l [ 2 ] = ( (
B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_113_0 [ 2 ] ; } { ( ( XDot_GP_T * )
ssGetdX ( S ) ) -> Integrator_CSTATE_i [ 0 ] = ( ( B_GP_T * ) _ssGetBlockIO (
S ) ) -> B_0_110_0 [ 0 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) ->
Integrator_CSTATE_i [ 1 ] = ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_110_0
[ 1 ] ; ( ( XDot_GP_T * ) ssGetdX ( S ) ) -> Integrator_CSTATE_i [ 2 ] = ( (
B_GP_T * ) _ssGetBlockIO ( S ) ) -> B_0_110_0 [ 2 ] ; } }
#define MDL_ZERO_CROSSINGS
static void mdlZeroCrossings ( SimStruct * S ) { B_GP_T * _rtB ; P_GP_T *
_rtP ; ZCV_GP_T * _rtZCSV ; _rtZCSV = ( ( ZCV_GP_T * )
ssGetSolverZcSignalVector ( S ) ) ; _rtP = ( ( P_GP_T * ) ssGetDefaultParam (
S ) ) ; _rtB = ( ( B_GP_T * ) _ssGetBlockIO ( S ) ) ; _rtZCSV ->
Saturation_UprLim_ZC [ 0 ] = _rtB -> B_0_46_0 [ 0 ] - _rtP -> P_32 [ 0 ] ;
_rtZCSV -> Saturation_LwrLim_ZC [ 0 ] = _rtB -> B_0_46_0 [ 0 ] - _rtP -> P_33
[ 0 ] ; _rtZCSV -> Saturation_UprLim_ZC [ 1 ] = _rtB -> B_0_46_0 [ 1 ] - _rtP
-> P_32 [ 1 ] ; _rtZCSV -> Saturation_LwrLim_ZC [ 1 ] = _rtB -> B_0_46_0 [ 1
] - _rtP -> P_33 [ 1 ] ; _rtZCSV -> Saturation_UprLim_ZC [ 2 ] = _rtB ->
B_0_46_0 [ 2 ] - _rtP -> P_32 [ 2 ] ; _rtZCSV -> Saturation_LwrLim_ZC [ 2 ] =
_rtB -> B_0_46_0 [ 2 ] - _rtP -> P_33 [ 2 ] ; _rtZCSV ->
Saturation_UprLim_ZC_i [ 0 ] = _rtB -> B_0_97_0 [ 0 ] - _rtP -> P_68 [ 0 ] ;
_rtZCSV -> Saturation_LwrLim_ZC_o [ 0 ] = _rtB -> B_0_97_0 [ 0 ] - _rtP ->
P_69 [ 0 ] ; _rtZCSV -> Saturation_UprLim_ZC_i [ 1 ] = _rtB -> B_0_97_0 [ 1 ]
- _rtP -> P_68 [ 1 ] ; _rtZCSV -> Saturation_LwrLim_ZC_o [ 1 ] = _rtB ->
B_0_97_0 [ 1 ] - _rtP -> P_69 [ 1 ] ; _rtZCSV -> Saturation_UprLim_ZC_i [ 2 ]
= _rtB -> B_0_97_0 [ 2 ] - _rtP -> P_68 [ 2 ] ; _rtZCSV ->
Saturation_LwrLim_ZC_o [ 2 ] = _rtB -> B_0_97_0 [ 2 ] - _rtP -> P_69 [ 2 ] ;
} static void mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0
, 842126867U ) ; ssSetChecksumVal ( S , 1 , 3553287976U ) ; ssSetChecksumVal
( S , 2 , 3026801603U ) ; ssSetChecksumVal ( S , 3 , 2161784243U ) ; {
mxArray * slVerStructMat = NULL ; mxArray * slStrMat = mxCreateString (
"simulink" ) ; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , &
slVerStructMat , 1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray *
slVerMat = mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat ==
NULL ) { status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar ,
10 ) ; } } mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ;
if ( ( status == 1 ) || ( strcmp ( slVerChar , "8.1" ) != 0 ) ) { return ; }
} ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork
( S ) != sizeof ( DW_GP_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file." ) ; } if ( ssGetSizeofGlobalBlockIO ( S
) != sizeof ( B_GP_T ) ) { ssSetErrorStatus ( S ,
"Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file." ) ; } { int ssSizeofParams ;
ssGetSizeofParams ( S , & ssSizeofParams ) ; if ( ssSizeofParams != sizeof (
P_GP_T ) ) { static char msg [ 256 ] ; sprintf ( msg ,
"Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file." ) ; } } _ssSetDefaultParam ( S , (
real_T * ) & GP_rtDefaultP ) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; ( (
P_GP_T * ) ssGetDefaultParam ( S ) ) -> P_32 [ 0 ] = rtInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_32 [ 1 ] = rtInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_32 [ 2 ] = rtInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_33 [ 0 ] = rtMinusInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_33 [ 1 ] = rtMinusInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_33 [ 2 ] = rtMinusInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_68 [ 0 ] = rtInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_68 [ 1 ] = rtInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_68 [ 2 ] = rtInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_69 [ 0 ] = rtMinusInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_69 [ 1 ] = rtMinusInf ; ( ( P_GP_T * )
ssGetDefaultParam ( S ) ) -> P_69 [ 2 ] = rtMinusInf ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { } static void mdlTerminate (
SimStruct * S ) { }
#include "simulink.c"
