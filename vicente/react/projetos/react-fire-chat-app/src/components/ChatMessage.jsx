import "./ChatMessage.css";

function ChatMessage(props) {
  const messageClass = "sent"; // recent
  return (
    <>
      <div className={`message ${messageClass}`}>
        <div className="bubble">
          <img className="avatar" src="https://api.dicebear.com/6.x/bottts/png" alt="avatar" />
          <div className="display-message">
            <strong>Vicente Calfo</strong>
            <p>Esta é nossa mensagem de placeholder</p>
            <small>28/04/2023</small>
          </div>
        </div>
      </div>
    </>
  );
};

export default ChatMessage;