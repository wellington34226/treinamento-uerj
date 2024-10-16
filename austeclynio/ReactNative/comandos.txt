npm install -g create-react-native-app react-native-cli react-native-git-upgrade react-native-cli expo-cli eas-cli
create-react-native-app projeto
cd projeto
npm install --save react-native-screens react-native-safe-area-context @react-navigation/native @react-navigation/native-stack @react-navigation/bottom-tabs @react-native-community/netinfo@9.3.7
npx expo install react checkbox react-native-web react-dom react-native-screens react-native-safe-area-context expo-splash-screen react-native @expo/webpack-config

Debug USB
https://medium.com/@psyanite/how-to-connect-expo-to-usb-android-device-16b83ff67428
Debug WiFi
npx expo start

Build
eas build -p android
eas build -p android --profile preview
Publish PlayStore
eas submit --platform android 

Versão mínima
node 18.16.0
npm 9.6.5


Actuware UOL protocolo 20230701014676  20230701014752 chamdo 1119246691 - Não é possível acessar ftpCriado em: 28/07/2023 , às 20h57