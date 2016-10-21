<?xml version="1.0" encoding="ASCII"?>
<ResourceModel:App xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:ResourceModel="http://www.infineon.com/Davex/Resource.ecore" name="DIM_BCCU" URI="http://resources/4.1.6/app/DIM_BCCU/0" description="DIM_BCCU APP configures the dimming engine registers of&#xA;the Brightness and Color Control Unit (BCCU).&#xA;It also provides dynamic APIs to high level APPs such as &#xA;DALI_CG and PDM_DIMMED_LED_LAMP." mode="NOTSHARABLE" version="4.1.6" minDaveVersion="4.0.0" instanceLabel="DIM_BCCU_0" appLabel="">
  <upwardMapList xsi:type="ResourceModel:RequiredApp" href="../../PDM_DIMMED_LED_LAMP/v4_0_4/PDM_DIMMED_LED_LAMP_0.app#//@requiredApps.0"/>
  <properties provideInit="true"/>
  <virtualSignals name="dimming_level_output" URI="http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout" hwSignal="dimout" hwResource="//@hwResources.0" visible="true">
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../PDM_DIMMED_LED_LAMP/v4_0_4/PDM_DIMMED_LED_LAMP_0.app#//@connections.0"/>
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../PDM_DIMMED_LED_LAMP/v4_0_4/PDM_DIMMED_LED_LAMP_0.app#//@connections.1"/>
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../PDM_DIMMED_LED_LAMP/v4_0_4/PDM_DIMMED_LED_LAMP_0.app#//@connections.2"/>
    <upwardMapList xsi:type="ResourceModel:Connections" href="../../PDM_DIMMED_LED_LAMP/v4_0_4/PDM_DIMMED_LED_LAMP_0.app#//@connections.3"/>
  </virtualSignals>
  <requiredApps URI="http://resources/4.1.6/app/DIM_BCCU/0/appres_global_bccu" requiredAppName="GLOBAL_BCCU" requiringMode="SHARABLE">
    <downwardMapList xsi:type="ResourceModel:App" href="../../GLOBAL_BCCU/v4_1_6/GLOBAL_BCCU_0.app#/"/>
  </requiredApps>
  <hwResources name="Dimming Engine" URI="http://resources/4.1.6/app/DIM_BCCU/0/hwres_dimming_engine" resourceGroupUri="peripheral/bccu/0/dimming_engine/0" constraintType="GLOBAL_RESOURCE" mResGrpUri="peripheral/bccu/*/dimming_engine/*">
    <downwardMapList xsi:type="ResourceModel:ResourceGroup" href="../../../HW_RESOURCES/BCCU0/BCCU0_0.dd#//@provided.30"/>
  </hwResources>
  <connections URI="http://resources/4.1.6/app/DIM_BCCU/0/http://resources/4.1.6/app/DIM_BCCU/0/vs_dimout/http://resources/4.1.8/app/PDM_BCCU/0/vs_pdmbccu_dimin" sourceSignal="dimming_level_output" targetSignal="dimming_level_input" srcVirtualSignal="//@virtualSignals.0">
    <downwardMapList xsi:type="ResourceModel:VirtualSignal" href="../../PDM_BCCU/v4_1_8/PDM_BCCU_0.app#//@virtualSignals.2"/>
    <targetVirtualSignal href="../../PDM_BCCU/v4_1_8/PDM_BCCU_0.app#//@virtualSignals.2"/>
  </connections>
</ResourceModel:App>
