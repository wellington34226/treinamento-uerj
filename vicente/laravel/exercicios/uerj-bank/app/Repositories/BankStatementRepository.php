<?php

namespace App\Repositories;

use Illuminate\Support\Facades\DB;

class BankStatementRepository{

    public function getByUserId($userId){
       $data = DB::select('select * from transaction where userId = :userId', ['userId' => $userId]);
       return $data;
    }

}
