@component('layouts/layout-sidebar')
  @slot('activePath') {{ $activePath }} @endslot
  @slot('title') {{ $title }} @endslot
  <h1>PIX</h1>
  <h2>{{ $name }}</h2>
@endcomponent
