import React from "react";
import { Text, View } from "react-native";
import styles from "./styles"; // Aqui os estilos serão importados

export default function App() {
  return (
    <View style={styles.container}>
      {/* <View style={styles.box}>
        <Text style={styles.boxText}>Uma Caixa!!!</Text>
      </View> */}
      <View style={styles.box}>
        <Text style={styles.boxText}>Caixa 1!!!</Text>
      </View>
      <View style={styles.box}>
        <Text style={styles.boxText}>Caixa 2!!!</Text>
      </View>
      <View style={styles.box}>
        <Text style={styles.boxText}>Caixa 3!!!</Text>
      </View>
    </View>
  );
}