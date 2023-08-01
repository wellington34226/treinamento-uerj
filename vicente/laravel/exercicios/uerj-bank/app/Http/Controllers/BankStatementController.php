<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\UseCases\BankStatementUseCase;
use Illuminate\Support\Facades\Auth;

class BankStatementController extends Controller{
  public function __construct(private BankStatementUseCase $bankStatementUseCase){}

  public function index(Request $request){
    $title = "Extrato";
    $bankStatement = $this->bankStatementUseCase->getByUserId(Auth::user()->id);
    //var_dump($bankStatement);
    return view('bankStatement/index',[
      'activePath' => $request->path(),
      'title' => $title,
      'bankStatement' => $bankStatement
    ]);
  }
}
