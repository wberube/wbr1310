<!-- === BEGIN SIDENAV === -->
<ul>
<?
$link_on="sidenavoff";

if($MY_NAME=="st_device")
	{echo "<li><div id='".$link_on."'>".		$m_menu_st_device.	"</div></li>\n";	}
else	{echo "<li><div><a href='/st_device.php'>".	$m_menu_st_device.	"</a></div></li>\n";	}

if($MY_NAME=="st_log")
	{echo "<li><div id='".$link_on."'>".		$m_menu_st_log.		"</div></li>\n";	}
else	{echo "<li><div><a href='/st_log.php'>".	$m_menu_st_log.		"</a></div></li>\n";	}

if($MY_NAME=="st_stats")
	{echo "<li><div id='".$link_on."'>".		$m_menu_st_stats.	"</div></li>\n";	}
else	{echo "<li><div><a href='/st_stats.php'>".	$m_menu_st_stats.	"</a></div></li>\n";	}

if($MY_NAME=="st_wlan")
	{echo "<li><div id='".$link_on."'>".		$m_menu_st_wlan.	"</div></li>\n";	}
else	{echo "<li><div><a href='/st_wlan.php'>".	$m_menu_st_wlan.	"</a></div></li>\n";	}
?>
</ul>
<!-- === END SIDENAV === -->
