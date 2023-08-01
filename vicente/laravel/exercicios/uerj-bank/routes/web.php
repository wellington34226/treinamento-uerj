<?php

use Illuminate\Support\Facades\Route;
use App\Http\Controllers\DashboardController;
use App\Http\Controllers\LoginController;
use App\Http\Controllers\PixController;
use App\Http\Controllers\BankStatementController;

/*
|--------------------------------------------------------------------------
| Web Routes
|--------------------------------------------------------------------------
|
| Here is where you can register web routes for your application. These
| routes are loaded by the RouteServiceProvider and all of them will
| be assigned to the "web" middleware group. Make something great!
|
*/

//Route::get('/', function () {return view('welcome');});
Route::redirect('/','/login');

Route::get('/login', [LoginController::class,'index'])->name('login');
Route::post('/auth', [LoginController::class,'auth'])->name('login.auth');
Route::get('/sair', [LoginController::class,'logout'])->name('logout');

Route::get('/pix/{name?}', [PixController::class,'index'])->middleware('auth');
Route::get('/extrato', [BankStatementController::class,'index'])->middleware('auth');
Route::get('/dashboard', [DashboardController::class,'index'])->middleware('auth');
