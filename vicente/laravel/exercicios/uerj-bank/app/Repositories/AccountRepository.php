<?php
namespace App\Repositories;

use Illuminate\Support\Facades\DB;

class AccountRepository{

  public function getByUserId($userId){
    $data = DB::select('select * from account where userId = :userId',['userId' => $userId]);
    return $data[0];
  }
}
