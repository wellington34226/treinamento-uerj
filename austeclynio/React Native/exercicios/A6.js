import React from 'react';  
import {SafeAreaView,ActivityIndicator,Text,Modal,StyleSheet,View,FlatList} from 'react-native';  

const styles = StyleSheet.create({  
  container: {  
    margin: 10,  
    paddingTop: 40,  
    backgroundColor: 'white',  
  },  
  itemStyle: {  
    backgroundColor: '#ffc700',  
    padding: 10,  
    marginVertical: 8,  
    color: 'black',  
  },
  item2Style: {  
    backgroundColor: '#0066CC',  
    padding: 10,  
    marginVertical: 0,  
    color: 'white',  
  },  
  headerStyle: {
    width: '100%',
    height: 45,
    backgroundColor: '#606070',
  },
  textStyle: {
    textAlign: 'center',
    color: '#fff',
    fontSize: 18,
    padding: 7,
  },
  centeredView: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    marginTop: 22,
  },
  modalView: {
    margin: 20,
    backgroundColor: 'white',
    borderRadius: 20,
    padding: 35,
    alignItems: 'center',
    shadowColor: '#000',
    shadowOffset: {
      width: 0,
      height: 2,
    },
    shadowOpacity: 0.25,
    shadowRadius: 4,
    elevation: 5,
  },    
  modalText: {
    marginBottom: 15,
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

const App = () => {  
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
  const PaginaModal = () => {
    return (
      <Modal
        animationType="fade"
        transparent={true}
        visible={carros.length>0 ? true : false}
        onRequestClose={() => {
          setCarros([]);
          setMarcaCarro('');
        }}>
        <View style={styles.centeredView}>
          <View style={styles.modalView}>
            <Text style={styles.modalText}>{marcaCarro.toUpperCase()}</Text>
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
              renderItem={({item}) => {
                return (
                  <Text style={styles.item2Style}>{item.modelo} | {item.ano} | {item.cor}</Text>
                );
              }}
              onEndReachedThreshold={0.1}
            />
            {/* 
          <Text>{JSON.stringify(carros)}</Text>
          */}
          </View>
        </View>
      </Modal>
    )
  };
  const ItemView = ({item}) => {  
    return (  
      <Text style={styles.itemStyle} onPress={() => {setMarcaCarro(item.title);}}>
        {item.title.toUpperCase()}  
      </Text>  
    );  
  };
  const PaginaList = () => {
    return (
      <View style={styles.container}>  
        <FlatList  
          data={DATA}  
          keyExtractor={item => item.title}  
          renderItem={ItemView}  
          onEndReachedThreshold={0.1}		  
        />  
      </View>  
    )
  };

  React.useEffect(() => {
    getCarros();
  }, [marcaCarro]);

  return (  
    <SafeAreaView style={{flex: 1}}>
      {isLoading ?(<ActivityIndicator />):(<PaginaList />)}
      <PaginaModal />
    </SafeAreaView>  
  );
};

export default App;