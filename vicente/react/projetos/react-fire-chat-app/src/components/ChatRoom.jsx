import "./ChatRoom.css";
import ChatMessage from "./ChatMessage";

function ChatRoom(){
  return(
    <>
      <div className='chat-room'>
        <main>
        <ChatMessage />
        </main>
        <div className='form'>
          <form>
            <input placeholder='Vamos conversar' type='text'/>
            <button type='submit'>
              <img src='./sent.png' alt='Botão de enviar'/>
            </button>
          </form>
        </div>
      </div>
    </>
  );
};

export default ChatRoom;