<?php
namespace App\Repositories;

use Illuminate\Support\Facades\DB;

class UserRepository{
  public function getById($id){
    $data = DB::select('select * from users where id = :id',['id' => $id]);
    return $data[0];
  }
}
