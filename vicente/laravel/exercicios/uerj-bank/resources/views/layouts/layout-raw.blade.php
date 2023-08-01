@if (isset($customCss))
  @include('layouts/head',['customCss' => $customCss])
@else
  @include('layouts/head')
@endif
  {{ $slot }}
@include('layouts/footer')
