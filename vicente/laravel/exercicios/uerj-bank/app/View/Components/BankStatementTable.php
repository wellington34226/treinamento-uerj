<?php

namespace App\View\Components;

use Closure;
use Illuminate\Contracts\View\View;
use Illuminate\View\Component;

class BankStatementTable extends Component{
    /**
     * Create a new component instance.
     */
    public $bankStatement;

    public function __construct($bankStatement){$this->bankStatement = $bankStatement;}

    /**
     * Get the view / contents that represent the component.
     */
    public function render(): View|Closure|string{
        return view('components.bank-statement-table');
    }
}
