/* eslint-disable jsx-a11y/alt-text */
import './App.css';
import ChatRoom from './components/ChatRoom';
import SignIn from './components/SignIn';

import {initializeApp} from 'firebase/app';
import {getAuth} from 'firebase/auth';
import {getFirestore} from 'firebase/firestore';

const firebaseConfig ={
  apiKey:process.env.REACT_APP_API_KEY,
  authDomain:process.env.REACT_APP_AUTH_DOMAIN,
  projectId:process.env.REACT_APP_PROJECT_ID,
  storageBucket:process.env.REACT_APP_STORAGE_BUCKET,
  messagingSenderId:process.env.REACT_APP_MESSAGING_SENDER_ID,
  appId:process.env.REACT_APP_ID
};

const firebaseApp = initializeApp(firebaseConfig);
const auth = getAuth(firebaseApp);
const firestore = getFirestore(firebaseApp);

function App() {
  return (
    <div className="App">
      <header>
        <div className="logo">
          <div>
            <img src="/logo.png" />
          </div>
          <div>
            <h1>FireChate</h1>
            <h2>React Firebase Chat</h2>
          </div>
        </div>
        <div className="user"></div>
      </header>
      <SignIn auth={auth}></SignIn>
      <ChatRoom />
    </div>
  );
}

export default App;
