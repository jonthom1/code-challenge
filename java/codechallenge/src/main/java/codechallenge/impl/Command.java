package codechallenge.impl;

public class Command {
	private int cmd;
	private String user;
	private String message;
	
	public static int PUBLISH = 0;
	public static int TIMELINE = 1;
	public static int FOLLOW = 2;
	public static int WALL = 3;
	
	Command( final int _cmd
			, final String _user
			, final String _message) 
	{
		cmd = _cmd;
		user = _user;
		message = _message;
	}
	
	public int getCmd() {
		return cmd;
	}

	public void setCmd(int cmd) {
		this.cmd = cmd;
	}

	public String getUser() {
		return user;
	}

	public void setUser(String user) {
		this.user = user;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}
	
	
}
