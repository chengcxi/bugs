; DSL GEM ENGINE 2 Gates of Hell
; File: 		arm_vehicle_def_placement.inc
; Catalog: 		set\interaction_entity\interaction_entity_arm
; Created by: 	Max Drechsler
; Created:		30.08.2026
; Modify by:	Max Drechsler
; Modify:		30.08.2026
; Version:		1.0
; Description: 

; ============================================================
; GERMANY TANKS (добавлены отсутствующие)
; ============================================================

	;-	{"panzer1b"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer2c"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer2f"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"pz35t"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"pz38t_a"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"pz38t_f"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer35s"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer3e"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer3f"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer3h"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer3j"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer3j1"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer3l"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer3m"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer3n"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer4f1"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer4f2"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer4g"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer4h"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer4j"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer5d"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer5a"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer5g"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"tiger1h"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"tiger1e"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"tiger2h"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"stug3a"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"stug3f"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"stug3g"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"jagdpanzer4_l48"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"hetzer"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"ferdinand"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"elefant"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"jagdpanther"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"jagdtiger88"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"marder2"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"marder3m"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"nashorn"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"sturer_emil"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"dicker_max"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"hummel"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"wespe"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzerwerfer42"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	; ============================================================
	;-	; RUSSIA TANKS (добавлены отсутствующие)
	;-	; ============================================================
	;-	
	;-	{"t40"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t30"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t60"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t70"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t70m"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t50"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"bt2"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"bt5"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"bt7"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t26_31"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t26_33"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t26_39"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t28"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t28_38"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t35"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"kv1_39"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"kv1_40"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"kv1_41"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"kv1_42"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"kv1s"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"kv85"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"is1_43"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"is2_43"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"is2_44"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"is_3"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t3476_40"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t3476_41"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t3476_41e"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t3476_42"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t3476_43"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t3485_43"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t3485_44"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"su76"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"su85"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"su100"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"su122"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"su152"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"isu152"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"isu122s"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"zsu_37"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	; ============================================================
	;-	; FINLAND TANKS (добавлены отсутствующие)
	;-	; ============================================================
	;-	
	;-	{"t26e"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"bt5_fin"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t28e_fin"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t3476_41_fin"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"panzer4j_fin"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"stug3g_fin"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"t3485_44_fin"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"comet"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	; ============================================================
	;-	; USA TANKS (добавлены отсутствующие)
	;-	; ============================================================
	;-	
	;-	{"m2a4_stuart"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m3_stuart_early"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m3_stuart_late"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m5a1_stuart"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m24_chaffee"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m4_75_early"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m4_75_late"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m4a1_75_early"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m4a1_75_mid"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m4a1_75_late"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m4a1_76w"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m4a3_75_late"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m4a3_76w"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m4a3e2_75"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m4a3e2_76"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m10_gmc"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m10_gmc_late"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m18_hellcat"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m36_gmc"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"m7_hmc"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	; ============================================================
	;-	; ENGLAND TANKS (добавлены отсутствующие)
	;-	; ============================================================
	;-	
	;-	{"vickers_mk6"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"cruiser_mk1"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"cruiser_mk2"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"cruiser_mk3"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"cruiser_mk4"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"crusader_mk1"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"crusader_mk2"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"crusader_mk3"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"valentine_mk1"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"valentine_mk2"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "early_stage" {tags add "early_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"valentine_mk9"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"valentine_mk10"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"cromwell4"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"cromwell5"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"comet1_a34"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"sherman1_armor"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"sherman1c_armor"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"sherman2_dv"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"sherman3_early"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"sherman5_late"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"sherman5c"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"churchill_mk3"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"churchill_mk4"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "mid_stage" {tags add "mid_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"churchill_mk7"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"achilles_mk2"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}
	;-	
	;-	{"archer"
	;-	    {on spawn {delay 5}
	;-	        {if not tagged "_user"
	;-	            {if tagged "cmp_mg"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "_ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "ai_defender"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	            {if tagged "no_scavenge"
	;-	                {if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
	;-	            }
	;-	        }
	;-				{if not user_control
	;-					{if not tagged "late_stage" {tags add "late_stage"}}
	;-				}
	;-	    }
	;-	}

; ============================================================
; CANNONS
; ============================================================

; ============================================================
; GERMANY – emplacments (исправлены теги)
; ============================================================

{"88mm_flak18_bot"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"panzernest_krab_ger"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"20mm_flak30"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"20mm_flak38"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"37mm_flak37"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"50mm_flak41"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

{"150mm_sw34_ger"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"28mm_pzb41"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"37mm_pak36"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"47mm_pakt"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"50mm_pak38"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"50mm_pak38_late"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"75mm_pak9738"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"75mm_pak40"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"88mm_flak18"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; period(mid)
		}
	}
}

{"88mm_flak36"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"88mm_pak4341"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

{"pak_44"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

{"75mm_leig18"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"75mm_legebig18"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"80mm_sgrw34"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"120mm_sgrw42"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"200mm_ldgw40"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"105mm_lefh18"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}


{"150mm_sig33"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"150mm_nebelwerfer41"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"210mm_nebelwerfer42"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

{"300mm_nebelwerfer42"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

; ============================================================
; RUSSIA – emplacments (исправлены теги)
; ============================================================

{"ds39_stand"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"dshk_stan"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"sg43_stand"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"maxim_x4"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"dshk_aa"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"25mm_72k"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"37mm_61k"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"ZP_3154B"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"76mm_m1938"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"85mm_52k_bot"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"85mm_52k"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"45mm_m37"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"76mm_m1902"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"76mm_m1933"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"76mm_f22"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"57mm_zis2"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"76mm_zis3"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"57mm_zis2_late"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

{"d-44"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"100mm_bs3"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"76mm_m1902"	; второй экземпляр
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"76mm_m1927"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"76mm_m43"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"82mm_bm37"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"82mm_bm37_ai"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"120mm_pm38"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"160mm_mt_13_mortar"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}	; <-- исправлено
		}
	}
}

{"122mm_a19"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"107mm_m1910_30"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"122mm_m1910"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

; ============================================================
; FINLAND – emplacments (исправлены теги)
; ============================================================

{"maxim_m1910_30"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"150mm_sw34"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"panzernest_krab"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"20mm_itk35"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"20mm_itk40"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"75mm_itk37_bot"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"40mm_itk38b"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}	; <-- исправлено
		}
	}
}

{"76mm_itk31"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}	; <-- исправлено
		}
	}
}

{"75mm_itk37"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}	; <-- исправлено
		}
	}
}

{"37mm_pstk36"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"45mm_pstk32"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"47mm_pstk39"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"45mm_pstk32_mid"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}	; <-- исправлено
		}
	}
}

{"50mm_pstk38"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"76mm_k00"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"76mm_k02"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"76mm_k02_30_40"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"76mm_k36"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"76mm_k36_mid"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"76mm_k36_late"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено (несмотря на название)
		}
	}
}

{"75mm_pstk9738"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"75mm_k40"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"50mm_krh38"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"81mm_krh36"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"120mm_krh40"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"170mm_minewerfer"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"105mm_k13"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"105mm_k34"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"120mm_k78_31"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"150mm_h40"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

{"155mm_k17"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

{"203mm_h17"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"150mm_rkh41"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"210mm_h17"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}	; <-- исправлено
		}
	}
}

{"300mm_krh42"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

; ============================================================
; USA – emplacments (исправлены теги)
; ============================================================

{"m1917_30cal"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"m2_30cal_tripod"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"m2_50cal_tripod"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"50cal_quad_m45"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"40mm_m1"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"90mm_m1a1"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"37mm_m3a1"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"57mm_m1"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"57mm_m1_late"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"76mm_m5_m1"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"60mm_m2"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}	; <-- исправлено
		}
	}
}

{"81mm_m1"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"107mm_m2"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"75mm_m1a1"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}	; <-- исправлено
		}
	}
}

{"75mm_m3a3"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"105mm_m2a1"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}	; <-- исправлено
		}
	}
}

{"114mm_m1"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

; ============================================================
; ENGLAND – emplacments (исправлены теги)
; ============================================================

{"40mm_qf2_early"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"40mm_qf40_early"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"57mm_qf6_mk4_early"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"76mm_qf17_25"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"76mm_qf17_mid"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

{"20mm_oerlikon"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"94mm_qf_3_7_aa_early"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"40mm_qf2_late"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"94mm_qf_3_7_aa_mid"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"76mm_qf17_early"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"94mm_qf_3_7_aa_late"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}

{"88mm_qf25_mk1_4p"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"114mm_bl_4_5_mk1"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "early_stage" {tags add "early_stage"}}
		}
	}
}

{"88mm_qf25_mk2"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "mid_stage" {tags add "mid_stage"}}
		}
	}
}

{"140mm_bl_5_5_late"
	{on spawn {delay 5}
	;	{if not tagged "_user"
			{if tagged "cmp_mg"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "_ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "ai_defender"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}
			{if tagged "no_scavenge"
				{if terrain_fx "ice" {tex_mod "winter"} else terrain_fx "snow" {tex_mod "winter"}}
			}	;1
	;	}	;2
		{if not user_control
			{if not tagged "late_stage" {tags add "late_stage"}}
		}
	}
}