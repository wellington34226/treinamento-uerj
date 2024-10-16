import React from 'react';  
import {useNetInfo} from "@react-native-community/netinfo";
import {Text,Button,View,StyleSheet,PermissionsAndroid,ImageBackground,FlatList} from 'react-native';

const styles = StyleSheet.create({
  container:{
    flex:1,
    alignItems: 'center',
  },
  image: {
    width: '100%',
    height: '100%',
    justifyContent: 'center'
  },
});

export function PaginaInfo(){
  const netInfo = useNetInfo();
  const [autorizado,setAutorizado] = React.useState(false);
  const requestPermission = async () => {
    try {
      const granted = await PermissionsAndroid.request(
        PermissionsAndroid.PERMISSIONS.ACCESS_FINE_LOCATION,
        {
          title: 'Permissão para dados da Rede',
          message:'Acesso aos dados da Rede',       
          buttonNegative: 'Cancelar',
          buttonPositive: 'OK',
        },
      );
      if (granted === PermissionsAndroid.RESULTS.GRANTED) {	
        setAutorizado(true);
      } else {
        setAutorizado(false);	  
      }
    } catch (err) {
      setAutorizado(false);
    }
  };
  const Wifi = () => {
    return (
      <View>
        <Text>Força do Sinal: {netInfo.details.strength}</Text>
        <Text>ssid: {netInfo.details.ssid}</Text>
        <Text>ipAddress: {netInfo.details.ipAddress}</Text>
        <Text>Link Speed: {netInfo.details.linkSpeed}</Text>
      </View>
    );
  };
  const MinhaRede = () => {
    return (
      <View style={styles.container}>
        <View style={{marginTop:20,padding:10,backgroundColor:'white'}}>
          <Text>Tipo: {netInfo.type}</Text>
          <Text>Estado: {netInfo.isConnected ? "Conectado"  : "Desconectado"}</Text>
          <Text>WiFi: {netInfo.isWifiEnabled ? "ON" : "OFF"}</Text>
          <Text>Internet: {netInfo.isInternetReachable ? "ON" : "OFF"}</Text>
          { netInfo.isWifiEnabled ? <Wifi/> : <Text>Operadora: {netInfo.details.carrier}</Text> }
          <Text>{JSON.stringify(netInfo,null,2)}</Text>
        </View>
      </View>
    );
  };
  return (  
    <ImageBackground source={require('./android/app/src/main/res/drawable/background.jpg')} resizeMode="cover" resizeMethod='scale' style={styles.image}>
      {autorizado ? (<MinhaRede/>) :  (<Button title="Pedir Permissão" onPress={requestPermission} />)}
    </ImageBackground>
  );
};