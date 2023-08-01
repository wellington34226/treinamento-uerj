import "./SignIn.css"

function SignIn({auth}) {
  const signInWithGoogle = () => {
    console.log(auth);
  };
  return (
    <div className="sign-in">
      <button onClick={signInWithGoogle}>
        <div>
          <img src="/google.png" alt="Google login" />
        </div>
        <div>Sign in with Google</div>
      </button>
    </div>
  );
};

export default SignIn;