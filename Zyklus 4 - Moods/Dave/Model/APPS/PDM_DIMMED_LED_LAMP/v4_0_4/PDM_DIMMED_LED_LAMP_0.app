<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="PDM_DIMMED_LED_LAMP" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0" description="Creates a virtual lamp with up to 9 BCCU channels,&#xA; optionally controls the peak current using various&#xA; internal driver methods. The APP provides a run-time&#xA; functions to change a color, dimming level and&#xA; adjustable peak current reference." mode="NOTSHARABLE" version="4.0.4" minDaveVersion="4.0.0" instanceLabel="PDM_DIMMED_LED_LAMP_0" appLabel="" containingProxySignal="true">
  <properties provideInit="true"/>
  <virtualSignals name="led_ch0_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_0" hwSignal="pad" hwResource="//@hwResources.0" required="false" visible="true"/>
  <virtualSignals name="led_ch1_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_1" hwSignal="pad" hwResource="//@hwResources.1" required="false" visible="true"/>
  <virtualSignals name="led_ch2_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_2" hwSignal="pad" hwResource="//@hwResources.2" required="false" visible="true"/>
  <virtualSignals name="led_ch3_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_3" hwSignal="pad" hwResource="//@hwResources.3" required="false" visible="true"/>
  <virtualSignals name="led_ch0_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_0" hwSignal="pad" hwResource="//@hwResources.4" required="false" visible="true"/>
  <virtualSignals name="led_ch1_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_1" hwSignal="pad" hwResource="//@hwResources.5" required="false" visible="true"/>
  <virtualSignals name="led_ch2_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_2" hwSignal="pad" hwResource="//@hwResources.6" required="false" visible="true"/>
  <virtualSignals name="led_ch3_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_3" hwSignal="pad" hwResource="//@hwResources.7" required="false" visible="true"/>
  <virtualSignals name="led_ch0_comp_out_pin_signal" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_0" hwSignal="pin" hwResource="//@hwResources.8"/>
  <virtualSignals name="led_ch0_ccu4_in_pin_signal" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_0" hwSignal="pin" hwResource="//@hwResources.9"/>
  <virtualSignals name="led_ch1_comp_out_pin_signal" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_1" hwSignal="pin" hwResource="//@hwResources.10"/>
  <virtualSignals name="led_ch1_ccu4_in_pin_signal" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_1" hwSignal="pin" hwResource="//@hwResources.11"/>
  <virtualSignals name="led_ch2_comp_out_pin_signal" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_2" hwSignal="pin" hwResource="//@hwResources.12"/>
  <virtualSignals name="led_ch2_ccu4_in_pin_signal" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_2" hwSignal="pin" hwResource="//@hwResources.13"/>
  <virtualSignals name="led_ch3_comp_out_pin_signal" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_3" hwSignal="pin" hwResource="//@hwResources.14"/>
  <virtualSignals name="led_ch3_ccu4_in_pin_signal" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_3" hwSignal="pin" hwResource="//@hwResources.15"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_dim_bccu" requiredAppName="DIM_BCCU">
    <downwardMapList xsi:type="ResourceModel:App" href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_global_bccu" requiredAppName="GLOBAL_BCCU" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pdm_bccu_1" requiredAppName="PDM_BCCU">
    <downwardMapList xsi:type="ResourceModel:App" href="../../PDM_BCCU/v4_1_8/PDM_BCCU_0.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pdm_bccu_2" requiredAppName="PDM_BCCU">
    <downwardMapList xsi:type="ResourceModel:App" href="../../PDM_BCCU/v4_1_8/PDM_BCCU_3.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pdm_bccu_3" requiredAppName="PDM_BCCU">
    <downwardMapList xsi:type="ResourceModel:App" href="../../PDM_BCCU/v4_1_8/PDM_BCCU_2.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pdm_bccu_4" requiredAppName="PDM_BCCU">
    <downwardMapList xsi:type="ResourceModel:App" href="../../PDM_BCCU/v4_1_8/PDM_BCCU_1.app#/"/>
  </requiredApps>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pdm_bccu_5" requiredAppName="PDM_BCCU" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pdm_bccu_6" requiredAppName="PDM_BCCU" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pdm_bccu_7" requiredAppName="PDM_BCCU" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pdm_bccu_8" requiredAppName="PDM_BCCU" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pdm_bccu_9" requiredAppName="PDM_BCCU" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_comp_ref_1" requiredAppName="COMP_REF" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu4_1" requiredAppName="PWM_CCU4" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu8_1" requiredAppName="PWM_CCU8" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_comp_ref_2" requiredAppName="COMP_REF" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu4_2" requiredAppName="PWM_CCU4" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu8_2" requiredAppName="PWM_CCU8" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_comp_ref_3" requiredAppName="COMP_REF" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu4_3" requiredAppName="PWM_CCU4" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu8_3" requiredAppName="PWM_CCU8" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_comp_ref_4" requiredAppName="COMP_REF" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu4_4" requiredAppName="PWM_CCU4" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu8_4" requiredAppName="PWM_CCU8" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_comp_ref_5" requiredAppName="COMP_REF" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu4_5" requiredAppName="PWM_CCU4" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu8_5" requiredAppName="PWM_CCU8" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_comp_ref_6" requiredAppName="COMP_REF" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu4_6" requiredAppName="PWM_CCU4" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu8_6" requiredAppName="PWM_CCU8" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_comp_ref_7" requiredAppName="COMP_REF" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu4_7" requiredAppName="PWM_CCU4" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu8_7" requiredAppName="PWM_CCU8" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_comp_ref_8" requiredAppName="COMP_REF" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu4_8" requiredAppName="PWM_CCU4" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu8_8" requiredAppName="PWM_CCU8" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_comp_ref_9" requiredAppName="COMP_REF" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu4_9" requiredAppName="PWM_CCU4" required="false"/>
  <requiredApps URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/appres_pwm_ccu8_9" requiredAppName="PWM_CCU8" required="false"/>
  <hwResources name="led_ch0_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/hwres_port_pin_comp_out_0" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="led_ch1_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/hwres_port_pin_comp_out_1" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="led_ch2_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/hwres_port_pin_comp_out_2" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="led_ch3_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/hwres_port_pin_comp_out_3" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="led_ch0_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/hwres_port_pin_ccu4_in_0" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="led_ch1_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/hwres_port_pin_ccu4_in_1" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="led_ch2_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/hwres_port_pin_ccu4_in_2" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="led_ch3_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/hwres_port_pin_ccu4_in_3" resourceGroupUri="" required="false" mResGrpUri="port/p/*/pad/*"/>
  <hwResources name="led_ch0_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_hwres_port_pin_comp_out_0" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="led_ch0_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_hwres_port_pin_ccu4_in_0" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="led_ch1_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_hwres_port_pin_comp_out_1" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="led_ch1_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_hwres_port_pin_ccu4_in_1" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="led_ch2_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_hwres_port_pin_comp_out_2" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="led_ch2_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_hwres_port_pin_ccu4_in_2" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="led_ch3_comp_out_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_hwres_port_pin_comp_out_3" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <hwResources name="led_ch3_ccu4_in_pin" URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_hwres_port_pin_ccu4_in_3" resourceGroupUri="" required="false" mResGrpUri="devicepackage/0/*"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_dim_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_1_dimin" systemDefined="true" sourceSignal="dimming_level_output" targetSignal="dimming_level_input" proxySrcVirtualSignalUri="http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout" proxyTargetVirtualSignalUri="http://resources/4.1.8/app/PDM_BCCU/0/vs_pdmbccu_dimin" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../PDM_BCCU/v4_1_8/PDM_BCCU_0.app#//@virtualSignals.2"/>
    <srcVirtualSignal href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_0.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_dim_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_2_dimin" systemDefined="true" sourceSignal="dimming_level_output" targetSignal="dimming_level_input" proxySrcVirtualSignalUri="http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout" proxyTargetVirtualSignalUri="http://resources/4.1.8/app/PDM_BCCU/1/vs_pdmbccu_dimin" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../PDM_BCCU/v4_1_8/PDM_BCCU_3.app#//@virtualSignals.2"/>
    <srcVirtualSignal href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_3.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_dim_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_3_dimin" systemDefined="true" sourceSignal="dimming_level_output" targetSignal="dimming_level_input" proxySrcVirtualSignalUri="http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout" proxyTargetVirtualSignalUri="http://resources/4.1.8/app/PDM_BCCU/2/vs_pdmbccu_dimin" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../PDM_BCCU/v4_1_8/PDM_BCCU_2.app#//@virtualSignals.2"/>
    <srcVirtualSignal href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_2.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_dim_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_4_dimin" systemDefined="true" sourceSignal="dimming_level_output" targetSignal="dimming_level_input" proxySrcVirtualSignalUri="http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout" proxyTargetVirtualSignalUri="http://resources/4.1.8/app/PDM_BCCU/3/vs_pdmbccu_dimin" containingProxySignal="true">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../PDM_BCCU/v4_1_8/PDM_BCCU_1.app#//@virtualSignals.2"/>
    <srcVirtualSignal href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_1.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_dim_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_5_dimin" systemDefined="true" sourceSignal="dimming_level_output" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout" containingProxySignal="true">
    <srcVirtualSignal href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_dim_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_6_dimin" systemDefined="true" sourceSignal="dimming_level_output" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout" containingProxySignal="true">
    <srcVirtualSignal href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_dim_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_7_dimin" systemDefined="true" sourceSignal="dimming_level_output" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout" containingProxySignal="true">
    <srcVirtualSignal href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_dim_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_8_dimin" systemDefined="true" sourceSignal="dimming_level_output" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout" containingProxySignal="true">
    <srcVirtualSignal href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_dim_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_9_dimin" systemDefined="true" sourceSignal="dimming_level_output" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout" containingProxySignal="true">
    <srcVirtualSignal href="../../DIM_BCCU/v4_1_6/DIM_BCCU_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_global_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_1_dimin" systemDefined="true" sourceSignal="global_dimming_level" targetSignal="dimming_level_input" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/GLOBAL_BCCU/0/vs_global_dimming_engine" proxyTargetVirtualSignalUri="http://resources/4.1.8/app/PDM_BCCU/0/vs_pdmbccu_dimin" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#//@virtualSignals.6"/>
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_0.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_global_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_2_dimin" systemDefined="true" sourceSignal="global_dimming_level" targetSignal="dimming_level_input" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/GLOBAL_BCCU/0/vs_global_dimming_engine" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#//@virtualSignals.6"/>
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_3.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_global_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_3_dimin" systemDefined="true" sourceSignal="global_dimming_level" targetSignal="dimming_level_input" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/GLOBAL_BCCU/0/vs_global_dimming_engine" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#//@virtualSignals.6"/>
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_2.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_global_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_4_dimin" systemDefined="true" sourceSignal="global_dimming_level" targetSignal="dimming_level_input" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/GLOBAL_BCCU/0/vs_global_dimming_engine" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#//@virtualSignals.6"/>
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_1.app#//@virtualSignals.2"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_global_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_5_dimin" systemDefined="true" sourceSignal="global_dimming_level" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/GLOBAL_BCCU/0/vs_global_dimming_engine" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#//@virtualSignals.6"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_global_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_6_dimin" systemDefined="true" sourceSignal="global_dimming_level" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/GLOBAL_BCCU/0/vs_global_dimming_engine" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#//@virtualSignals.6"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_global_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_7_dimin" systemDefined="true" sourceSignal="global_dimming_level" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/GLOBAL_BCCU/0/vs_global_dimming_engine" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#//@virtualSignals.6"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_global_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_8_dimin" systemDefined="true" sourceSignal="global_dimming_level" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/GLOBAL_BCCU/0/vs_global_dimming_engine" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#//@virtualSignals.6"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_global_bccu_dimout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_9_dimin" systemDefined="true" sourceSignal="global_dimming_level" required="false" proxySrcVirtualSignalUri="http://resources/4.1.6/app/GLOBAL_BCCU/0/vs_global_dimming_engine" containingProxySignal="true">
    <srcVirtualSignal href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#//@virtualSignals.6"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_1_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_1_mci" systemDefined="true" sourceSignal="pdm_output" required="false" proxySrcVirtualSignalUri="http://resources/4.1.8/app/PDM_BCCU/0/vs_pdmbccu_out" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_1_event_generator_pdout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_1_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_1_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_1_in" systemDefined="true" targetSignal="gating_input" required="false" proxyTargetVirtualSignalUri="http://resources/4.1.8/app/PDM_BCCU/0/vs_pdmbccu_in" containingProxySignal="true">
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_0.app#//@virtualSignals.3"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_1_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_1_gp0_unsync" systemDefined="true" sourceSignal="pdm_output" required="false" proxySrcVirtualSignalUri="http://resources/4.1.8/app/PDM_BCCU/0/vs_pdmbccu_out" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_1_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_1_gp1_unsync" systemDefined="true" sourceSignal="pdm_output" required="false" proxySrcVirtualSignalUri="http://resources/4.1.8/app/PDM_BCCU/0/vs_pdmbccu_out" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_0.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_2_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_2_mci" systemDefined="true" sourceSignal="pdm_output" required="false" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_3.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_2_event_generator_pdout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_2_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_2_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_2_in" systemDefined="true" targetSignal="gating_input" required="false" containingProxySignal="true">
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_3.app#//@virtualSignals.3"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_2_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_2_gp0_unsync" systemDefined="true" sourceSignal="pdm_output" required="false" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_3.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_2_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_2_gp1_unsync" systemDefined="true" sourceSignal="pdm_output" required="false" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_3.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_3_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_3_mci" systemDefined="true" sourceSignal="pdm_output" required="false" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_2.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_3_event_generator_pdout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_3_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_3_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_3_in" systemDefined="true" targetSignal="gating_input" required="false" containingProxySignal="true">
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_2.app#//@virtualSignals.3"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_3_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_3_gp0_unsync" systemDefined="true" sourceSignal="pdm_output" required="false" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_2.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_3_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_3_gp1_unsync" systemDefined="true" sourceSignal="pdm_output" required="false" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_2.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_4_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_4_mci" systemDefined="true" sourceSignal="pdm_output" required="false" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_1.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_4_event_generator_pdout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_4_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_4_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_4_in" systemDefined="true" targetSignal="gating_input" required="false" containingProxySignal="true">
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_1.app#//@virtualSignals.3"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_4_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_4_gp0_unsync" systemDefined="true" sourceSignal="pdm_output" required="false" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_1.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_4_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_4_gp1_unsync" systemDefined="true" sourceSignal="pdm_output" required="false" containingProxySignal="true">
    <srcVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_1.app#//@virtualSignals.0"/>
  </connections>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_5_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_5_mci" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_5_event_generator_pdout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_5_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_5_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_5_in" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_5_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_5_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_5_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_5_gp1_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_6_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_6_mci" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_6_event_generator_pdout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_6_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_6_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_6_in" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_6_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_6_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_6_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_6_gp1_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_7_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_7_mci" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_7_event_generator_pdout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_7_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_7_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_7_in" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_7_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_7_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_7_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_7_gp1_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_8_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_8_mci" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_8_event_generator_pdout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_8_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_8_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_8_in" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_8_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_8_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_8_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_8_gp1_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_9_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_9_mci" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_9_event_generator_pdout/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_9_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_9_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_9_in" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_9_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_9_gp0_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_pdm_bccu_9_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu8_9_gp1_unsync" systemDefined="true" required="false" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_1_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_0" systemDefined="true" targetSignal="led_ch0_comp_out_pin" required="false" targetVirtualSignal="//@virtualSignals.0" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_1_gp0_unsync" systemDefined="true" sourceSignal="led_ch0_ccu4_in_pin" required="false" srcVirtualSignal="//@virtualSignals.4" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_2_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_1" systemDefined="true" targetSignal="led_ch1_comp_out_pin" required="false" targetVirtualSignal="//@virtualSignals.1" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_1/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_2_gp0_unsync" systemDefined="true" sourceSignal="led_ch1_ccu4_in_pin" required="false" srcVirtualSignal="//@virtualSignals.5" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_3_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_2" systemDefined="true" targetSignal="led_ch2_comp_out_pin" required="false" targetVirtualSignal="//@virtualSignals.2" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_2/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_3_gp0_unsync" systemDefined="true" sourceSignal="led_ch2_ccu4_in_pin" required="false" srcVirtualSignal="//@virtualSignals.6" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_comp_ref_4_out/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_3" systemDefined="true" targetSignal="led_ch3_comp_out_pin" required="false" targetVirtualSignal="//@virtualSignals.3" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_3/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pwm_ccu4_4_gp0_unsync" systemDefined="true" sourceSignal="led_ch3_ccu4_in_pin" required="false" srcVirtualSignal="//@virtualSignals.7" containingProxySignal="true"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_0" systemDefined="true" sourceSignal="led_ch0_comp_out_pin" targetSignal="led_ch0_comp_out_pin_signal" srcVirtualSignal="//@virtualSignals.0" targetVirtualSignal="//@virtualSignals.8"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_0" systemDefined="true" sourceSignal="led_ch0_comp_out_pin_signal" targetSignal="led_ch0_comp_out_pin" srcVirtualSignal="//@virtualSignals.8" targetVirtualSignal="//@virtualSignals.0"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_0" systemDefined="true" sourceSignal="led_ch0_ccu4_in_pin" targetSignal="led_ch0_ccu4_in_pin_signal" srcVirtualSignal="//@virtualSignals.4" targetVirtualSignal="//@virtualSignals.9"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_0" systemDefined="true" sourceSignal="led_ch0_ccu4_in_pin_signal" targetSignal="led_ch0_ccu4_in_pin" srcVirtualSignal="//@virtualSignals.9" targetVirtualSignal="//@virtualSignals.4"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_1/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_1" systemDefined="true" sourceSignal="led_ch1_comp_out_pin" targetSignal="led_ch1_comp_out_pin_signal" srcVirtualSignal="//@virtualSignals.1" targetVirtualSignal="//@virtualSignals.10"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_1/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_1" systemDefined="true" sourceSignal="led_ch1_comp_out_pin_signal" targetSignal="led_ch1_comp_out_pin" srcVirtualSignal="//@virtualSignals.10" targetVirtualSignal="//@virtualSignals.1"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_1/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_1" systemDefined="true" sourceSignal="led_ch1_ccu4_in_pin" targetSignal="led_ch1_ccu4_in_pin_signal" srcVirtualSignal="//@virtualSignals.5" targetVirtualSignal="//@virtualSignals.11"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_1/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_1" systemDefined="true" sourceSignal="led_ch1_ccu4_in_pin_signal" targetSignal="led_ch1_ccu4_in_pin" srcVirtualSignal="//@virtualSignals.11" targetVirtualSignal="//@virtualSignals.5"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_2/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_2" systemDefined="true" sourceSignal="led_ch2_comp_out_pin" targetSignal="led_ch2_comp_out_pin_signal" srcVirtualSignal="//@virtualSignals.2" targetVirtualSignal="//@virtualSignals.12"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_2/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_2" systemDefined="true" sourceSignal="led_ch2_comp_out_pin_signal" targetSignal="led_ch2_comp_out_pin" srcVirtualSignal="//@virtualSignals.12" targetVirtualSignal="//@virtualSignals.2"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_2/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_2" systemDefined="true" sourceSignal="led_ch2_ccu4_in_pin" targetSignal="led_ch2_ccu4_in_pin_signal" srcVirtualSignal="//@virtualSignals.6" targetVirtualSignal="//@virtualSignals.13"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_2/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_2" systemDefined="true" sourceSignal="led_ch2_ccu4_in_pin_signal" targetSignal="led_ch2_ccu4_in_pin" srcVirtualSignal="//@virtualSignals.13" targetVirtualSignal="//@virtualSignals.6"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_3/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_3" systemDefined="true" sourceSignal="led_ch3_comp_out_pin" targetSignal="led_ch3_comp_out_pin_signal" srcVirtualSignal="//@virtualSignals.3" targetVirtualSignal="//@virtualSignals.14"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_comp_out_3/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_comp_out_3" systemDefined="true" sourceSignal="led_ch3_comp_out_pin_signal" targetSignal="led_ch3_comp_out_pin" srcVirtualSignal="//@virtualSignals.14" targetVirtualSignal="//@virtualSignals.3"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_3/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_3" systemDefined="true" sourceSignal="led_ch3_ccu4_in_pin" targetSignal="led_ch3_ccu4_in_pin_signal" srcVirtualSignal="//@virtualSignals.7" targetVirtualSignal="//@virtualSignals.15"/>
  <connections URI="http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/__pin_vs_pdm_dimmed_led_lamp_ccu4_in_3/http://resources/4.0.4/app/PDM_DIMMED_LED_LAMP/0/vs_pdm_dimmed_led_lamp_ccu4_in_3" systemDefined="true" sourceSignal="led_ch3_ccu4_in_pin_signal" targetSignal="led_ch3_ccu4_in_pin" srcVirtualSignal="//@virtualSignals.15" targetVirtualSignal="//@virtualSignals.7"/>
</ResourceModel:App>
