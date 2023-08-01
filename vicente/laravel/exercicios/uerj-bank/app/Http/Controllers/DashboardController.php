<?php

namespace App\Http\Controllers;

use Illuminate\Http\Request;
use App\UseCases\AccountUseCase;
use App\UseCases\UserUseCase;
use Illuminate\Support\Facades\Auth;

class DashboardController extends Controller{
  public function __construct(
    private AccountUseCase $accountUseCase,
    private UserUseCase $userUseCase,
  ){}
  //1 vicente, 15 alexandre, 17 pedro, 19 matheus, 16 paulo
  public function index(Request $request){
    $title = "Dashboard";
    $id = Auth::user()->id;
    $account = $this->accountUseCase->getByUserId($id);
    $user = $this->userUseCase->getById($id);
    return view('dashboard/index',[
      'activePath' => $request->path(),
      'title' => $title,
      'account' => $account,
      'user' => $user,
    ]);
  }
}
