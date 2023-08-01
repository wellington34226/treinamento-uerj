<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>UERJ Bank {{ $title ? " - ".$title : "" }}</title>
    <link rel="stylesheet" href="/css/app.css">
    @if(isset($customCss))
    <link rel="stylesheet" href="/css/{{$customCss}}.css">
    @endif
    <link rel="stylesheet" href="https://cdn.jsdelivr.net/npm/bulma@0.9.4/css/bulma.min.css">
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.7.0/jquery.min.js"></script>
    <script src="https://igorescobar.github.io/jQuery-Mask-Plugin/js/jquery.mask.min.js"></script>
</head>
<body>
