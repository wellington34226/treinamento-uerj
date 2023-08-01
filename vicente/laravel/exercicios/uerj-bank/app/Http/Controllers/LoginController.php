<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Auth;

class LoginController extends Controller{
    public function index(Request $request){
      $title = "Login";
      return view('login/index',['title' => $title]);
    }
    public function auth(Request $request){
      $credentials = $request->validate([
          'email' => ['required','email'],
          'password' => ['required'],
        ],
        [
          'email.required' => 'O e-mail é obrigatório.',
          'email.email' => 'O e-mail não é válido.',
          'password.required' => 'A senha é obrigatória.'
        ]
      );
      if(Auth::attempt($credentials)){
        $request->session()->regenerate();
        return redirect('/dashboard');
      }else{
        return redirect()->back()->with('error', 'Credenciais inválidas');
      }
    }
    public function logout(Request $request){
      Auth::logout();
      $request->session()->invalidate();
      $request->session()->regenerateToken();
      return redirect('/login');
    }
}
