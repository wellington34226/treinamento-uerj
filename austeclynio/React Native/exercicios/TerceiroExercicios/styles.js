import { Platform, StyleSheet, StatusBar } from 'react-native';

export default StyleSheet.create({
  container: {
    flex: 1,
    flexDirection: 'row',
    //flexDirection: 'column',
    flexWrap: 'wrap',
    backgroundColor: 'ghostwhite',
    justifyContent: 'space-between',
    alignItems: 'center',
    ...Platform.select({
      ios: { paddingTop: 20 },
      android: { paddingTop: StatusBar.currentHeight }
    })
  },
  box: {
    height: 100,
    width: 100,
    justifyContent: 'center',
    alignItems: 'center',
    backgroundColor: 'lightgray',
    borderWidth: 1,
    borderStyle: 'dashed',
    borderColor: 'darkslategray',
    margin: 0
  },
  boxText: {
    color: 'darkslategray',
    fontWeight: 'bold'
  }
});