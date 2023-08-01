<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use Illuminate\Support\Facades\Auth;

class PixController extends Controller{
  public function index(Request $request,string $name = ''){
    $title = "PIX";

    return view('pix/index',[
      'activePath' => $request->path(),
      'title' => $title,
      'name' => $name
    ]);
  }
}
