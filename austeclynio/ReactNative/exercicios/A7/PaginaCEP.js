import React from 'react';  
import {Text,Button,TextInput,StyleSheet,View} from 'react-native';

const styles = StyleSheet.create({
  container: {
    flex: 1,
    padding: 10,
  },
  input: {
    height: 40,
    borderWidth: 0.5,
  },
  titulo: {    
    margin: 6,    
    padding: 5,
    fontWeight: 'bold',
  },  
});

export function PaginaCEP (){  
  const [cepnumber,onChangeNumber] = React.useState('');
  const [logradouro,onLogradouro] = React.useState('');
  const [bairro,onBairro] = React.useState('');
  const [localidade,onLocalidade] = React.useState('');
  const [encontrou,onEncontrou] = React.useState(false);
  const [pesquisou,onPesquisou] = React.useState(false);
  
  const PegaCEP = async () => {
    try {
      const response = await fetch('http://152.92.181.90:8080/CursoJavaScript/PegaCEPJson',{	  
	    method: 'POST',
      headers: {'Content-type': 'application/x-www-form-urlencoded; charset=UTF-8'},
      body: JSON.stringify({cep: cepnumber})
      });
      if (response.ok) {
        const json = await response.json();
        onEncontrou(json.encontrou);
        onLogradouro(json.logradouro);
        onBairro(json.bairro);
        onLocalidade(json.localidade);
      }else{		  
        alert('Algo não funcionou: ' +  response.status);
        onEncontrou(false);
        onLogradouro('');
        onBairro('');
        onLocalidade('');
      }
    } catch (error) {
      onEncontrou(false);
      onLogradouro('');
      onBairro('');
      onLocalidade('');
    } 
  };
  
  const apertou = () => {      
    if (!cepnumber.trim()) {
      alert('Tem que digitar!!!' );
      onPesquisou(false);
      onEncontrou(false);
      onLogradouro('');
      onBairro('');
      onLocalidade('');
    }else if (cepnumber.trim().length<8) {		
      alert('Tem que ter 8 dígitos!!!');     
      onPesquisou(false);
      onEncontrou(false);
      onLogradouro('');
      onBairro('');
      onLocalidade('');
    }else{
      onPesquisou(true);
      PegaCEP();
    }
  };
  const CEP = () => {
    if(pesquisou){
      if(encontrou){
        return(
          <View style={{marginTop: 10}}>
            <Text style={styles.titulo}>Logradouro:	{logradouro}</Text>
            <Text style={styles.titulo}>Bairro:	{bairro}</Text>
            <Text style={styles.titulo}>Localidade:	{localidade}</Text>
          </View>
        );
      }else{
        return(<Text style={styles.titulo}>CEP não encontrado</Text>);
      }
    }else{
      return(<Text style={styles.titulo}>Informe um CEP</Text>);
    }
  };
  return (
    <View style={styles.container}>
      <TextInput
        style={styles.input}
        onChangeText={onChangeNumber}
        value={cepnumber}
        keyboardType="numeric"
        autoCapitalize='none'
      />
			<View style={{marginTop: 10}}>
				<Button  				
					onPress={apertou}
					title = "Submeter"
					color="#606070"						
				/>	
			</View>
      <CEP />
		</View>
  );
};
