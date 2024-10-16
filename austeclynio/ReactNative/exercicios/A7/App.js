import React from 'react';  
import {StyleSheet,View,Text,StatusBar,Image} from 'react-native';
import {Ionicons } from '@expo/vector-icons';
import { NavigationContainer } from '@react-navigation/native';
import {createBottomTabNavigator} from '@react-navigation/bottom-tabs';
import {PaginaInfo} from './PaginaInfo.js';
import {PaginaCarros} from './PaginaCarros.js';
import {PaginaCEP} from './PaginaCEP.js';

const styles = StyleSheet.create({
  container: {
    flex:1,
    backgroundColor: 'white',
  },
});

const Tab = createBottomTabNavigator();

export default function App() {
  function HeaderBar({name}){
    return(
      <View style={{display:'flex',flexDirection:'row'}}>
        <Image source={require('./android/app/src/main/res/drawable/logo.png')} style={{width:50,height:50}}/>
        <Text style={{alignItems:'center',fontSize:20}}>{name}</Text>
      </View>
    );
  };

  return (
    <View style={styles.container}>
      <StatusBar hidden={false} />
      <NavigationContainer>
        <Tab.Navigator
          screenOptions={({ route }) => ({
            tabBarIcon: ({ focused, color, size }) => {
              let iconName;
              if (route.name === 'info') {
                iconName = focused ? 'information-circle': 'information-circle-outline';
              } else if (route.name === 'cars') {
                iconName = focused ? 'car-sport-sharp': 'car-sport-outline';
              }else if(route.name === 'cep') {
                iconName = focused ? 'mail-open': 'mail-outline';
              }
              return <Ionicons name={iconName} size={size} color={color} />;
            },
            tabBarActiveTintColor: 'tomato',
            tabBarInactiveTintColor: 'gray',
            headerTitle: () => {
              if (route.name === 'info') {
                return <HeaderBar name="Informações" />;
              } else if (route.name === 'cars') {
                return <HeaderBar name="Marcas de Carros" />;
              }else if(route.name === 'cep') {
                return <HeaderBar name="CEP" />;
              }
            }
          })}
        >
          <Tab.Screen name="info" component={PaginaInfo} options={{title:"Informações"}}/>
          <Tab.Screen name="cars" component={PaginaCarros} options={{title:"Marcas de Carros"}}/>
          <Tab.Screen name="cep" component={PaginaCEP} options={{title:"CEP"}}/>
        </Tab.Navigator>
      </NavigationContainer>
    </View>
  );
};