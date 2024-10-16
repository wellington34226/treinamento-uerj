import React, { useState } from 'react';
import {View,Text,Button,Alert,StyleSheet,StatusBar} from 'react-native';
import {WebView} from 'react-native-webview';

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  title: {
    textAlign: 'center',
    marginVertical: 8,
	  fontSize:20,
  },
  separator: {
    marginVertical: 8,
    //borderBottomColor: '#737373',
    //borderBottomWidth: StyleSheet.hairlineWidth,
  },
});

const Separator = () => <View style={styles.separator} />;

export default function App(){
  const [webviewVisible, setWebViewVisible] = useState(false);

  return(
    <View style={styles.container}>
      <StatusBar hidden={false} /> 
      <Text style={styles.title}>Exercício A3 - WebView</Text>
	    <Separator />
      <Button title='EXIBIR PÁGINA WEB' color='green' onPress={() => setWebViewVisible(true)}/>
	    <Separator />
      <Button title='INIBIR PÁGINA WEB' color='red' onPress={() => setWebViewVisible(false)}/>
	    <Separator />
      <View style={webviewVisible===true ? {flex:1} : {flex:0}}><WebView source={{uri: 'https://www.horariodebrasilia.org',}}/></View>
    </View>
  );
};