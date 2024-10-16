import React from 'react';  
import {ActivityIndicator,Text,StyleSheet,View,FlatList} from 'react-native';

const styles = StyleSheet.create({
  container: {
    backgroundColor: 'white',
  },
  itemStyle: {  
    backgroundColor: '#ffc700',  
    padding: 10,
    marginVertical: 8,  
    color: 'black',
    textAlign: 'center',
  },
  itemSelected :{
    backgroundColor: '#0066CC',
    padding: 10,
    marginVertical: 0,
    color: 'white',
    textAlign: 'center',
  },
  item2Style: {
    backgroundColor: '#0066CC',
    padding: 10,
    marginVertical: 0,
    color: 'white',
    textAlign: 'center',
  },
  headerStyle: {
    marginTop: 20,
    fontSize: 20,
    backgroundColor: '#606070',
  },
  textStyle: {
    width: '100%',
    textAlign: 'center',
    color: '#fff',
    fontSize: 18,
    padding: 10,
  },
  modalText: {
    textAlign: 'center',
    fontSize: 20,
  },
});

const DATA = [ 
  {title: "fiat"}, 
  {title: "gm"}, 
  {title: "vw"}, 
  {title: "ford"}, 
];

export function PaginaCarros(){
  const [isLoading, setLoading] = React.useState(false);
  const [carros,setCarros] = React.useState([]);
  const [marcaCarro,setMarcaCarro] = React.useState('');
  
  const getCarros = async () => {
    if(marcaCarro!==''){
      setLoading(true);
      try {
        const response = await fetch(
          'http://152.92.181.90:8080/CursoJavaScript/EnviarMenuJson',
          {
            method: "POST",
            body: "{marca:"+marcaCarro+"}",
          }
        );
        if(response.ok){
          const json = await response.json();
          if(!json.erro){
            setCarros(json.Carros);
          }
        }
      } catch (error) {
        console.error(error);
      } finally {
        setLoading(false);
      }
    }
  };
  
  function ListaMarcas(){
    return (
      <View style={styles.container}>  
        <FlatList
          data={DATA}
          keyExtractor={item => item.title}
          renderItem={({item}) => (<Text style={item.title===marcaCarro?styles.itemSelected:styles.itemStyle} onPress={() => {setMarcaCarro(item.title);}}>{item.title.toUpperCase()}</Text>)}
          onEndReachedThreshold={0.1}
        />
      </View>
    )
  };
  function ListaCarros(){
    if(carros.length>0){
      return(
        <View style={styles.container}>
          <FlatList
            data={carros}
            keyExtractor={item => item.id}
            ListHeaderComponent={() => {
              return (
                <View style={styles.headerStyle}>
                  <Text style={styles.textStyle}>MODELO | ANO | COR</Text>
                </View>
              );
            }}
            renderItem={({item}) => (<Text style={styles.item2Style}>{item.modelo} | {item.ano} | {item.cor}</Text>)}
            onEndReachedThreshold={0.1}
          />
        </View>
      );
    }else{
      return('');
    }
  };
  
  React.useEffect(() => {
    getCarros();
  }, [marcaCarro]);
  return (
    <View style={styles.container}>
      <ListaMarcas />
      {isLoading ?(<ActivityIndicator />):(<ListaCarros />)}
    </View>
  );
};