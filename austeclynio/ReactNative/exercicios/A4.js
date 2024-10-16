import React from 'react';
import {View,Text,TextInput,Button,Alert,StyleSheet,StatusBar} from 'react-native';
import WebView from 'react-native-webview';

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
  input: {
    width: '100%',
    height: 40,
    paddingHorizontal: 5,
    borderWidth: 0.5,
    marginTop: 15,
  },
});

const Separator = () => <View style={styles.separator} />;

export default function App(){
  
  const [webviewVisible, setWebViewVisible] = React.useState(false);
  const [url,onChangeUrl] = React.useState('');
  const PaginaWeb = () => {return (<View style={{flex:1}}><WebView source={{uri:url,}}/></View>)};

  return(
    <View style={styles.container}>
      <StatusBar hidden={false} /> 
      <Text style={styles.title}>Exercício A4 - WebView</Text>
	    <Separator />
        <TextInput
          style={styles.input}
          onChangeText={onChangeUrl}
          value={url}
          placeholder="http(s)://dominio:porta/caminho"
        />
	    <Separator />
      <Button title='EXIBIR PÁGINA WEB' color='green' onPress={() => url==='' ? Alert.alert("Idiota não informou a URL!") : (url.startsWith('http://') || url.startsWith('https://')) ? setWebViewVisible(true) : Alert.alert("URL inválida mané, use http:// ou https://")} />
	    <Separator />
      <Button title='INIBIR PÁGINA WEB' color='red' onPress={() => setWebViewVisible(false)}/>
	    <Separator />
      {webviewVisible==true ? <PaginaWeb /> : ''}
    </View>
  );
};