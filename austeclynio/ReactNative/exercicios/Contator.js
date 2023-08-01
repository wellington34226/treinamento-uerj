import { StatusBar } from 'expo-status-bar';
import React, {useState} from 'react';
import { StyleSheet, Text, View , Button} from 'react-native';

const Contador = () => {
  const [contador,setContador] = useState(10);
  return (
    <View>
      <Text>{contador}</Text>
      <Button title='Clique aqui' onPress={() => setContador(contador+1)} />
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    backgroundColor: '#fff',
    alignItems: 'center',
    justifyContent: 'center',
  },
});

export default function App() {
  return (
    <View style={styles.container}>
      <Contador/>
      <StatusBar style="auto" />
    </View>
  );
};
