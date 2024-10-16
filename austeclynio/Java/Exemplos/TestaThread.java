class TestaThread implements Runnable {
    private String message;
    public TestaThread(String s){
        this.message=s;
    }
    public void run() {
        System.out.println(Thread.currentThread().getName()+" (Inicio) message = "+message);
        processmessage();
        System.out.println(Thread.currentThread().getName()+" (Fim)");
    }
    private void processmessage() {
        try { Thread.sleep(2000); } catch (InterruptedException e) { e.printStackTrace(); }
    }
}