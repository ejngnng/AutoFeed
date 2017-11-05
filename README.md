# auto_feed_v2

This project is designed for auto feed system. Because CNC laster cutter for work is too slow. Arduino hardware and framwork is friendly to use. PlatformIO IDE with Atom for development. 

## main state

```mermaid
  graph TD;
  id_start((Power ON))-->id_config((Config));
  id_config-->id_feed((Feed);
  id_feed-->id_cut((cut));
  id_cut-->id_stop((stop));
  id_stop-->id_config;
```

## Feature List

| Feature | Status | Comments |
|:---------|:-----------|:---------|
| display |		|		|
| wireless|		|		|
| button  |		|		|
| motor	 |		|		|

## Plans

1.  homemade the machine.

2.  select the Arduino Board
