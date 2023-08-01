@component('layouts/layout-sidebar')
  @slot('activePath') {{ $activePath }} @endslot
  @slot('title') {{ $title }} @endslot
  <h2 class="title">Últimas 10 Transações</h2>
  <x-bank-statement-table :bankStatement="$bankStatement"/>
@endcomponent
