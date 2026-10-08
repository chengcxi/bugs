
;--------------New Modded
	{"tank.sherman_76_center_50_mace" ; 
		{clip
			{viewMin		-12}	; camera rotate upward limit (looking down)
			{viewMax		41 }	; camera rotate downward limit (looking up)
			{distanceMin	002}	; camera min distance from object. value / 20 = meters
			{distanceMax	350}	; camera max distance from object. value / 20 = meters
		}
		{level ;0
			{linkBone "body"}
			{faroffset 0 0 45}
			{nearoffset -40 0 60}
			{camera "zoom1"}
			;{hide_hitmarker 1}
			{blur_strength 2}
			{disable_fow 0}
			{no_grain}
		}
		{level ;1
			{zoom}
			;{vision_modes_active}
			{linkBone "sight"}
			{offset 1 0 2}
			{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_usa_m71d"}
			{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
			{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
			{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
			{distance 1}
			{distanceSet 0}
			{delta 0}
			{no_rim_light}
			{camera "zoom1"}
			{ManualAccuracyZoom}
			{blur_strength 5}
			{soundEffect "enclosed_vehicle"}
		}
		{level ;2
			{camera "zoom5"}
		}
		{level ;3
			{camera "zoom6"}
		}
		}

	{"artillery_4.common"
			{clip
				{viewMin		-40	}	; camera rotate upward limit (looking down)
				{viewMax		30	}	; camera rotate downward limit (looking up)
				{distanceMin	1	}	; camera min distance from object. value / 20 = meters
				{distanceMax	350	}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
			{faroffset 0 0 80}
			{nearoffset -25 0 90}
				{blur_strength 2}
				{disable_fow 0}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{vignette "/texture/common/environment/lens_effects/zoom_vignette_artillery_01"}
				{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_artillery_bp"}
				{distance 50}
				{distanceset 1}
				{delta 0}
			{linkBone "gun"}
				{offset 75 0 300}
				{gunnerviewoff 1}
				{camera "zoom1.5"}
				;{ManualAccuracyZoom}
				{blur_strength 10}
				{disable_fow 0}
				{no_rim_light}
				{soundEffect "opentop_vehicle"}
			}
			{level ;2
				{camera "zoom4"}
				{offset 100 0 500}
			}
			{level ;3
				{camera "zoom4"}
				{offset 200 0 600}
			}
			{level ;4
				{camera "zoom4"}
				{offset 300 0 700}
			}
			{level ;5
				{camera "zoom4"}
				{offset 400 0 800}
			}
			{level ;6
				{camera "zoom4"}
				{offset 500 0 900}
			}
			{level ;7
				{camera "zoom4"}
				{offset 600 0 1000}
			}
		}
		
	{"artillery_2.common"
			{clip
				{viewMin		-40	}	; camera rotate upward limit (looking down)
				{viewMax		30	}	; camera rotate downward limit (looking up)
				{distanceMin	1	}	; camera min distance from object. value / 20 = meters
				{distanceMax	350	}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
				{faroffset 0 0 85}
				{nearoffset -50 0 30}
				(mod "hardcore"
					{hide_crosshair 1}
					{hide_hitmarker 1}
				)
				{blur_strength 2}
				{disable_fow 0}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{vignette "/texture/common/environment/lens_effects/zoom_vignette_artillery_01"}
				{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_artillery_bp"}
				{distance 50}
				{distanceset 1}
				{delta 0}
			{linkBone "turret"}
				{offset 75 0 300}
				{gunnerviewoff 1}
				{camera "zoom1.5"}
				;{ManualAccuracyZoom}
				{blur_strength 10}
				{disable_fow 0}
				{no_rim_light}
				{soundEffect "opentop_vehicle"}
			}
			{level ;2
				{camera "zoom4"}
				{offset 100 0 500}
			}
			{level ;3
				{camera "zoom4"}
				{offset 200 0 600}
			}
			{level ;4
				{camera "zoom4"}
				{offset 300 0 700}
			}
			{level ;5
				{camera "zoom4"}
				{offset 400 0 800}
			}
			{level ;6
				{camera "zoom4"}
				{offset 500 0 900}
			}
			{level ;7
				{camera "zoom4"}
				{offset 600 0 1000}
			}
		}

	{"artillery_3.common"
		{clip
			{viewMin		-40	}	; camera rotate upward limit (looking down)
			{viewMax		30	}	; camera rotate downward limit (looking up)
			{distanceMin	1	}	; camera min distance from object. value / 20 = meters
			{distanceMax	350	}	; camera max distance from object. value / 20 = meters
		}
		{level ;0
			{linkBone "basis"}
			{faroffset 0 0 85}
			{nearoffset -50 0 30}
			(mod "hardcore"
				{hide_crosshair 1}
				{hide_hitmarker 1}
			)
			{blur_strength 2}
			{disable_fow 0}
		}
		{level ;1
			{zoom}
			{vision_modes_active}
			{vignette "/texture/common/environment/lens_effects/zoom_vignette_artillery_01"}
			{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
			{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
			{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_artillery_bp"}
			{distance 50}
			{distanceset 1}
			{delta 0}
			{linkBone "basis"}
			{offset 75 0 300}
			{gunnerviewoff 1}
			{camera "zoom1.5"}
			;{ManualAccuracyZoom}
			{blur_strength 10}
			{disable_fow 0}
			{no_rim_light}
			{soundEffect "opentop_vehicle"}
		}
		{level ;2
			{camera "zoom4"}
			{offset 100 0 500}
		}
		{level ;3
			{camera "zoom4"}
			{offset 200 0 600}
		}
		{level ;4
			{camera "zoom4"}
			{offset 300 0 700}
		}
		{level ;5
			{camera "zoom4"}
			{offset 400 0 800}
		}
		{level ;6
			{camera "zoom4"}
			{offset 500 0 900}
		}
		{level ;7
			{camera "zoom4"}
			{offset 600 0 1000}
		}
	}
	
		{"truck.flak30_2"
			{clip
				{viewMin		-15	}	; camera rotate upward limit (looking down)
				{viewMax		50		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	300		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"gun_rot1"}
				{faroffset 		0 10 45}
				{nearoffset		-20 10 25}
				{camera			"zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				
				{linkBone		"gun_rot"}
				
				{scope_vignette		"/texture/common/environment/lens_effects/vehicle_telescope_ger_20mm"}
				;{bump_spec_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01"}
				{blur_mask		"/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				
				;{hide_crosshair}
				{distance		18	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		40 -4 4 }
				{camera			"zoom1.5"	}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{no_rim_light}
				
				{soundEffect	"opentop_vehicle"}
			}
			{level ;2
				{camera			"zoom3"	}
			}
		}
		
		{"truck.flak30_3"
			{clip
				{viewMin		-15	}	; camera rotate upward limit (looking down)
				{viewMax		50		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	300		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"turret"}
				{faroffset 		0 10 45}
				{nearoffset		-20 10 25}
				{camera			"zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				
				{linkBone		"gun_rot"}
				
				{scope_vignette		"/texture/common/environment/lens_effects/vehicle_telescope_ger_20mm"}
				;{bump_spec_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01"}
				{blur_mask		"/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				
				;{hide_crosshair}
				{distance		18	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		40 -4 4 }
				{camera			"zoom1.5"	}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{no_rim_light}
				
				{soundEffect	"opentop_vehicle"}
			}
			{level ;2
				{camera			"zoom3"	}
			}
		}
		
		{"truck.flak30_4"
			{clip
				{viewMin		-15	}	; camera rotate upward limit (looking down)
				{viewMax		50		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	300		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"turret"}
				{faroffset 		0 10 45}
				{nearoffset		-20 10 25}
				{camera			"zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				
				{linkBone		"gun_rot"}
				
				{scope_vignette		"/texture/common/environment/lens_effects/vehicle_telescope_ger_20mm"}
				;{bump_spec_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01"}
				{blur_mask		"/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				
				;{hide_crosshair}
				{distance		18	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		40 -4 10 }
				{camera			"zoom1.5"	}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{no_rim_light}
				
				{soundEffect	"opentop_vehicle"}
			}
			{level ;2
				{camera			"zoom3"	}
			}
		}
		
{"vehicle.t77e1"
	{clip
		{viewMin		-20}	; camera rotate upward limit (looking down)
		{viewMax		30 }	; camera rotate downward limit (looking up)
		{distanceMin	1}		; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -65 0 55}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "gun_rot"}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_usa_m18"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 1}
		{distanceSet 0}
		{delta 0}
		{offset 10 0 10}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{no_grain}
		{no_rim_light}
		{with_owner
			{viewoff "gun_rot"}
		}
		{soundEffect "opentop_vehicle"}
	}
}
		
		{"truck.flak30_5"
			{clip
				{viewMin		-15	}	; camera rotate upward limit (looking down)
				{viewMax		50		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	300		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"turret"}
				{faroffset 		0 10 45}
				{nearoffset		-20 10 25}
				{camera			"zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				
				{linkBone		"gun_rot"}
				
				{scope_vignette		"/texture/common/environment/lens_effects/vehicle_telescope_ger_20mm"}
				;{bump_spec_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01"}
				{blur_mask		"/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				
				;{hide_crosshair}
				{distance		18	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		60 -4 10 }
				{camera			"zoom1.5"	}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{no_rim_light}
				
				{soundEffect	"opentop_vehicle"}
			}
			{level ;2
				{camera			"zoom3"	}
			}
		}
		
		{"tank.panzer2l_2" 
			{clip
				{viewMin		-12}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	200}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
				{faroffset 0 0 50}
				{nearoffset -20 0 50}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "turret"}
				{offset 42 5.0 20}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_4"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom2.4"}
			}
		}
		
		{"tank.panhard_2"
			{clip
				{viewMin		-15}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	200}	; camera min distance from object. value / 20 = meters
				{distanceMax	400}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
				{faroffset 0 0 70}
				{nearoffset -40 0 60}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "visor1"}
				{offset 10 0 6}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_ger_l711"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 5}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "opentop_vehicle"}
			}
			{level ;2
				{camera "zoom4"}
			}
		}
		
		{"tank.puma_2" ;
			{clip
				{viewMin		-12}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	200}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
				{faroffset 0 0 70}
				{nearoffset -45 0 60}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "turret"}
				{offset 50 -6.5 8}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_ger_tzf_4b"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{no_rim_light}
				{with_owner
					{viewoff "shieldt shieldl5 shieldr5"} ; removes shield to prevent clipping
				}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom2.5"}
			}
		}
		
		{"td.marder2_2" ; Marder II
			{clip
				{viewMin		-12}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	200}	; camera min distance from object. value / 20 = meters
				{distanceMax	400}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
				{faroffset 0 0 65}
				{nearoffset -40 0 60}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "visor1"}
				{offset 15 0 0}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_zf3x8ii"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 5}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "opentop_vehicle"}
			}
			{level ;2
				{camera "zoom4"}
			}
		}
		
		{"td.marder2_3" ; Marder II
			{clip
				{viewMin		-12}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	200}	; camera min distance from object. value / 20 = meters
				{distanceMax	400}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
				{faroffset 0 0 65}
				{nearoffset -40 0 60}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "visor1"}
				{offset 30 0 -1}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_zf3x8ii"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 5}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "opentop_vehicle"}
			}
			{level ;2
				{camera "zoom4"}
			}
		}
		
		{"tank.tiger2h_2" ; Tiger II late production turret
			{clip
				{viewMin		-15}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	-400}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "fxfire3"}
				{faroffset 0 0 45}
				{nearoffset 5 8 16}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "fxfire3"}
				{offset 60 -5 20}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9d"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom5"}
			}
		}
		
		{"tank.tiger2h_3" ; Tiger II late production turret
			{clip
				{viewMin		-15}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	-370}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "fxfire3"}
				{faroffset 0 8 45}
				{nearoffset 5 8 16}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "fxfire3"}
				{offset 72 0 20}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9d"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom5"}
			}
		}

		{"tank.tiger2h_3_3" ; Tiger II late production turret
			{clip
				{viewMin		-15}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	-370}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "gun_rot"}
				{faroffset 0 8 45}
				{nearoffset 5 8 16}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "gun_rot"}
				{offset 72 -10 5}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9d"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom5"}
			}
		}
		
		{"tank.tiger2h_3_4" ; Tiger II late production turret
			{clip
				{viewMin		-15}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	-370}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "gun_rot"}
				{faroffset 0 8 45}
				{nearoffset 5 8 16}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "gun_rot"}
				{offset 68 -12 12}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9d"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom5"}
			}
		}
	
		{"tank.tiger2h_4" ; Tiger II late production turret
			{clip
				{viewMin		-15}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	-400}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "fxfire3"}
				{faroffset 0 0 45}
				{nearoffset 5 8 16}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "fxfire3"}
				{offset 105 -10 20}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9d"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom5"}
			}
		}
		
		{"tank.tiger2h_5" ; Tiger II late production turret
			{clip
				{viewMin		-15}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	-400}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "fxfire3"}
				{faroffset 0 0 45}
				{nearoffset 5 8 16}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "fxfire3"}
				{offset 115 -10 20}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9d"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom5"}
			}
		}
		
		{"tank.tiger8" ; Tiger II late production turret
			{clip
				{viewMin		-15}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	-500}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "fxfire3"}
				{faroffset 0 0 55}
				{nearoffset 5 8 16}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "fxfire3"}
				{offset 75 -8 40}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9d"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom5"}
			}
		}
		
		{"tank.tiger_2" ; Tiger
			{clip
				{viewMin 		-12}	; camera rotate upward limit (looking down)
				{viewMax		 41}	; camera rotate downward limit (looking up)
				{distanceMin	002}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "gun_rot"}
				{faroffset 0 10 27}
				{nearoffset 5 10 10.5}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "turret"}
				{offset 55 8 10}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9b"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom5"}
			}
		}

		{"tank.type5" ; Tiger
			{clip
				{viewMin 		-12}	; camera rotate upward limit (looking down)
				{viewMax		 41}	; camera rotate downward limit (looking up)
				{distanceMin	002}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "gun_rot"}
				{faroffset -30 10 60}
				{nearoffset -10 10 25}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "turret"}
				{offset 70 -8 12}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9b"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{no_rim_light}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom5"}
			}
		}
		
		{"tank.panzer3l_2" ; Panzer III 50mm long barrel
			{clip
				{viewMin		-12}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	200}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
				{faroffset 0 0 70}
				{nearoffset -45 0 60}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "turret"}
				{offset 50 -6.5 8}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_5e"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{no_rim_light}
				{with_owner
					{viewoff "shieldt shieldl5 shieldr5"} ; removes shield to prevent clipping
				}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom2.5"}
			}
		}
		
		{"tank.panzer4h_2" ; Panzer IV H, J
			{clip
				{viewMin		-12}	; camera rotate upward limit (looking down)
				{viewMax		20 }	; camera rotate downward limit (looking up)
				{distanceMin	200}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "gun_rot"}
				{faroffset 0 0 70}
				{nearoffset -45 0 60}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "gun_rot1"}
				{offset 52 -8 1.5}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_5f1"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{no_rim_light}
				{with_owner
					{viewoff "shieldt turret_basket"} ; removes shield to prevent clipping
				}
				{soundEffect "enclosed_vehicle"}
			}
			{level ;2
				{camera "zoom2.5"}
			}
		}
		
		{"atgun.flak37_2"
			{clip
				{viewMin		-15	}	; camera rotate upward limit (looking down)
				{viewMax		50		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	300		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"gun_rot"}
				{faroffset 		0 5 53}
				{nearoffset		-15 5 35}
				{camera			"zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				
				{linkBone		"turret"}
				
				{scope_vignette		"/texture/common/environment/lens_effects/vehicle_telescope_ger_37mm"}
				;{bump_spec_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01"}
				{blur_mask		"/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				
				;{hide_crosshair}			
				{distance		5	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		-2 0 30}
				{camera			"zoom1.5"	}
				{ManualAccuracyZoom}
				{blur_strength 5}
				{disable_fow 0}
				{no_rim_light}
				
				{soundEffect	"opentop_vehicle"}
			}
			{level ;2
				{camera			"zoom3"	}
			}
		}

		{"vehicle.hanomag_2"
			{clip
				{viewMin		-20}	; camera rotate upward limit (looking down)
				{viewMax		30 }	; camera rotate downward limit (looking up)
				{distanceMin	200}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "gun_rot"}
				{faroffset 0 0 60}
				{nearoffset -30 0 45}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "gun_rot"}
				{vignette "/texture/common/environment/lens_effects/zoom_vignette_infantry_01"}
				{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{offset -15 8 9}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 10}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
		}

{"vehicle.hanomag_3"
	{clip
		{viewMin		-20}	; camera rotate upward limit (looking down)
		{viewMax		30 }	; camera rotate downward limit (looking up)
		{distanceMin	1}		; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -30 0 65}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{vignette "/texture/common/environment/lens_effects/zoom_vignette_infantry_01"}
		{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
		{distance 1}
		{distanceSet 0}
		{delta 0}
		{offset -45 0 9}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_grain}
		{no_rim_light}
		{soundEffect "opentop_vehicle"}
	}
}

		{"tank.panzer3n_2" ; Panzer III 75mm kwk 37
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		20 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -45 0 60}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 52 -8 20}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_5b"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{no_rim_light}
		{with_owner
			{viewoff "shieldt shieldl5 shieldr5"} ; removes shield to prevent clipping
		}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}

;----------------------- US vehicles MACE

{"tank.light_us37"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_37"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		70 -5 12	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us75"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_usa_m70f"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		70 8 12	};{offset		80 -5 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us_m6a1"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_usa_m70f"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		90 6 15	};{offset		80 -5 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}
	
		{"tank.medium_us75_2"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_usa_m70f"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		70 8 5	};{offset		80 -5 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us75_M4A3E2"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_usa_m70f"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 8 13	};{offset		80 -5 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}


		{"tank.medium_us75_m8a1"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_usa_m71d"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 8 8	};{offset		80 -5 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.light_us75_m24"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_75"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 -8 10	};{offset		80 -5 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us75_jumbo"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_75"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 8 12	};{offset		80 -5 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us75_howitzer"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_75_howitzer"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 8 8	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us75_m3_lee"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_75_m3_lee"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 -5 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}
			
		{"tank.medium_us76"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_76"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 8 12	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		

		{"tank.medium_us76_m10a1"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_76"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 -9 12	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us76_m10"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_76"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 -9 5	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us90_t15e1"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_t15e1"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 8 15	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us105_howitzer"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_105_howitzer"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		70 8 12	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

{"td.t95_t5e1"
		{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_t15e1"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 8 15	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
}

{"td.t95_t5e1_2"
		{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"visor1"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_t15e1"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		10 0 15	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
}

{"tank.light_us_m16"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_m16"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		95 -6 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

{"tank.light_us_m15a1"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_m15a1"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		95 -6 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

{"tank.light_us_m1a2_sep"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_m1a2_sep"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		95 -6 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

{"tank.light_us_m19"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_m19"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		95 -6 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}
			
		{"tank.medium_us_90_m6"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_m6"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		95 -6 50	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us_90_m36"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_m6"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		70 13 8	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us_90_m36b1"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_t15e1"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		70 13 22	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us_90_m36b1_2"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"gun_rot"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_t15e1"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		10 3 5	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}	

		{"tank.medium_us76_m18"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_m6"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		60 -10 12	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us_90_m26"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_usa_m76f"}
				{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		70 13 15	}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}
		
		{"tank.medium_us90_t15e1_2"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_t15e1"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		80 15 15}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

		{"tank.medium_us90_t15e1_3"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_t15e1"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		90 15 15}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}
		
		{"tank.medium_us_90_t30"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		0 0 60	}
				{nearoffset		0 0 70	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"turret"	}
				{vignette		"/texture/common/environment/lens_effects/vehicle_telescope_us_90_t15e1"}
				{blur_mask		"/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		90 15 15}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}
		
{"vehicle.us_car_mg"
	{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"gun_rot"	}
				{faroffset 		0 0 20	}
				{nearoffset		0 0 30	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"mgun"	}
				{vignette "/texture/common/environment/lens_effects/zoom_vignette_infantry_01"}
				{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		0 0 10}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

{"vehicle.us_car_mg_2"
	{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30		}	; camera rotate downward limit (looking up)
				{distanceMin	200		}	; camera min distance from object. value / 20 = meters
				{distanceMax	350		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"mgun1_rot"	}
				{faroffset 		0 0 20	}
				{nearoffset		0 0 30	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"mgun1_rot"	}
				{vignette "/texture/common/environment/lens_effects/zoom_vignette_infantry_01"}
				{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		0 0 20}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

{"vehicle.us_car_mg_3"
	{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		10		}	; camera rotate downward limit (looking up)
				{distanceMin	50		}	; camera min distance from object. value / 20 = meters
				{distanceMax	150		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"basis"	}
				{faroffset 		10 0  50	}
				{nearoffset		10 0  50	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"mgun"	}
				{vignette "/texture/common/environment/lens_effects/zoom_vignette_infantry_01"}
				{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		0 0 10}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

{"medium_mg.common_us"
			{clip
				{viewMin		-40	}	; camera rotate upward limit (looking down)
				{viewMax		90	}	; camera rotate downward limit (looking up)
				{distanceMin	55	}	; camera min distance from object. value / 20 = meters
				{distanceMax	150	}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
				{faroffset 0 0 40}
				{nearoffset 0 0 30}
			;	{delta 20}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{ManualAccuracyZoom}
			}
		}


{"tank.234_4_2" ; 7.5cm Pak 40 gun
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		20 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -45 0 60}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 45 -6.5 15.5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_zf3x8ii"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "opentop_vehicle"}
	}
	{level ;2
		{camera "zoom3"}
	}
}

{"vehicle.gmc_engineer"
	{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		10		}	; camera rotate downward limit (looking up)
				{distanceMin	50		}	; camera min distance from object. value / 20 = meters
				{distanceMax	150		}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone		"mgun"	}
				{faroffset 		10 0  10	}
				{nearoffset		10 0  10	}
				{camera			"zoom1"	}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
			{level ;1
				{zoom}
				{vision_modes_active	}
				{linkBone		"mgun"	}
				{vignette "/texture/common/environment/lens_effects/zoom_vignette_infantry_01"}
				{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
				{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_vehicle_01_bp"}
				{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
				{distance		50	}
				{distanceSet	0	}
				{delta 			0	}
				{offset		0 0 10}
				{camera			"zoom2"	}
				{ManualAccuracyZoom}
				{blur_strength 3}
				{disable_fow 0}
			}
			{level ;2
				{camera			"zoom4"	}
			}
		}

{"tank.is_MACE" ; 
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 80}
		{nearoffset -45 0 65}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 35 -7 18}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tsh17"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"tank.kv4b" ; 
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 80}
		{nearoffset -45 0 65}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 45 -7 18}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tsh17"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"tank.matilda_f96" ; 
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -45 0 60}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 25 -9 10}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_pt4-7"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}

{"atgun.zsu_37"
	{clip
		{viewMin		-15	}	; camera rotate upward limit (looking down)
		{viewMax		50	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	300	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 3 53}
		{nearoffset -15 3 43}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_hmg"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{offset 20 -7 20}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{no_rim_light}
		{with_owner
			{viewoff "shield"} ; removes shield to prevent clipping
		}
		{soundEffect "opentop_vehicle"}
	}
}

{"tank.zut_37" ; 
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 65}
		{nearoffset -30 0 45}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 20 -7 25}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tfmp1"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}

{"tank.t28_40" ; 
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 80}
		{nearoffset -45 0 65}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{offset 2 -17 1}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_pt"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"td.t28_85"
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -45 0 55}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{offset 8 -17 3}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tsh15"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"tank.t29" ; 
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 80}
		{nearoffset -45 0 65}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{offset 2 0 1}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_pt"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"tank.t3485_mace" 
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -50 0 65}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 25 -7 10}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tsh16"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
		{with_owner
			{viewoff "turret_grill_top"}
		}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}

{"tank.zsu_29k" 
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -50 0 65}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 10 7 10}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tsh16"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
		{with_owner
			{viewoff "turret_grill_top"}
		}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}

{"tank.panther_MACE" ; Panther tanks
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		 41}	; camera rotate downward limit (looking up)
		{distanceMin	002}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "fxfire3"}
		{faroffset 0 7 35}
		{nearoffset 2 7 20}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "fxfire3"}
		{offset 65 0 20}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_12a"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom5"}
	}
}

{"tank.panther_88_MACE" ; Panther tanks
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		 41}	; camera rotate downward limit (looking up)
		{distanceMin	002}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "fxfire3"}
		{faroffset 0 7 30}
		{nearoffset 5 7 16}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "fxfire3"}
		{offset 68 0 15}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9d"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom5"}
	}
}

{"tank.panther_ezart_MACE" ; Panther tanks
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		 41}	; camera rotate downward limit (looking up)
		{distanceMin	002}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "fxfire3"}
		{faroffset 0 7 30}
		{nearoffset 5 7 16}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "fxfire3"}
		{offset 68 -5 15}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_12a"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom5"}
	}
}

{"tank.panther_MACE_ussr" ; Panther tanks
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		 41}	; camera rotate downward limit (looking up)
		{distanceMin	002}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "fxfire3"}
		{faroffset 0 7 30}
		{nearoffset 5 7 16}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "fxfire3"}
		{offset 65 0 10}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tsh16"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom5"}
	}
}

{"tank.panther_new" ; Panther tanks
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		 41}	; camera rotate downward limit (looking up)
		{distanceMin	002}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "fxfire3"}
		{faroffset 0 7 40}
		{nearoffset 5 7 26}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "fxfire3"}
		{offset 65 0 25}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_12a"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom5"}
	}
}



{"tank.panzer2f_MACE" ; Panzer II
	{clip
		{viewMin		-11}	; camera rotate upward limit (looking down)
		{viewMax		24 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 50}
		{nearoffset -20 0 48}
		{camera "zoom1"}
		{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 44 -6 6.5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_4"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom2.4"}
	}
}

{"tank.tiger1h_mace_ussr"
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -45 0 55}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{offset 5 -17 2}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tsh19"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"tank.tiger1h_mace"
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -45 0 55}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{offset 5 -17 2}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_9b"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"td.su14_2"
	{clip
		{viewMin		-40	}	; camera rotate upward limit (looking down)
		{viewMax		30	}	; camera rotate downward limit (looking up)
		{distanceMin	1	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 65}
		{nearoffset -25 0 75}
		(mod "hardcore"
					{hide_crosshair 1}
					{hide_hitmarker 1}
				)
		{blur_strength 2}
		{disable_fow 0}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{vignette "/texture/common/environment/lens_effects/zoom_vignette_artillery_01"}
		{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_01"}
		{refraction_mask "/texture/common/environment/lens_effects/zoom_vignette_artillery_bp"}
		{distance 50}
		{distanceset 1}
		{delta 0}
		{linkBone "turret"}
		{offset 75 0 300}
		{gunnerviewoff 1}
		{camera "zoom1.5"}
		;{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "opentop_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
		{offset 100 0 500}
	}
	{level ;3
		{camera "zoom4"}
		{offset 200 0 600}
	}
	{level ;4
		{camera "zoom4"}
		{offset 300 0 700}
	}
	{level ;5
		{camera "zoom4"}
		{offset 400 0 800}
	}
	{level ;6
		{camera "zoom4"}
		{offset 500 0 900}
	}
	{level ;7
		{camera "zoom4"}
		{offset 600 0 1000}
	}
}

{"tank.panhard_mace"
	{clip
		{viewMin		-15}	; camera rotate upward limit (looking down)
		{viewMax		20 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	400}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -40 0 60}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 15 -10 5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_ger_l711"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{soundEffect "opentop_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"td.panzerjaeger_mace"
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		20 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	400}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 60}
		{nearoffset -30 0 50}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 20 -11 5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_zf3x8"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{with_owner
			{viewoff "turretshield"} ; removes shield to prevent clipping
		}
		{soundEffect "opentop_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"tank.panzer4f2_mace" ; Panzer IV F2, G
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		20 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -45 0 60}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 53.5 -8 10}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_5f"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}

{"tank.panther_fra_mace" ; Panther tanks
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		 41}	; camera rotate downward limit (looking up)
		{distanceMin	002}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "fxfire3"}
		{faroffset 0 7 30}
		{nearoffset 5 7 16}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "fxfire3"}
		{offset 55 -20 5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_12a"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom5"}
	}
}

{"td.sig33b_fra_mace"
	{clip
		{viewMin		-15	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	400	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 65}
		{nearoffset 20 0 80}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{offset 15 -3 6.5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_ger_rblf36"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom5"}
	}
}

{"tank.panzer38h_fra_mace" ; Panzer 38h 37mm
	{clip
		{viewMin		-16}	; camera rotate upward limit (looking down)
		{viewMax		25 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	250}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 10 0 75}
		{nearoffset 20 0 80}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 45 -8 6.5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_5a"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}

{"tank.panzer38h_fra_mace_2" ; Panzer 38h 37mm
	{clip
		{viewMin		-16}	; camera rotate upward limit (looking down)
		{viewMax		25 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	250}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 10 0 75}
		{nearoffset 20 0 80}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{offset 30 -15 5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_ger_rblf36"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}

{"tank.panhard_mace2"
	{clip
		{viewMin		-15}	; camera rotate upward limit (looking down)
		{viewMax		20 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	400}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 70}
		{nearoffset -40 0 60}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 25 -10 6.5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_ger_l711"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{disable_fow 0}
		{soundEffect "opentop_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"tank.sherman_75_whizbang" ; 
	{clip
		{viewMin		-12}	; camera rotate upward limit (looking down)
		{viewMax		41 }	; camera rotate downward limit (looking up)
		{distanceMin	002}	; camera min distance from object. value / 20 = meters
		{distanceMax	350}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "turret"}
		{faroffset 0 0 70}
		{nearoffset 5 0 50}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{offset 31 0 2}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_usa_m70f"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom3"}
	}
}

{"tank.t_42" ; 
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 80}
		{nearoffset -45 0 75}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "visor1"}
		{offset 15 2 5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tsh17"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom4"}
	}
}

{"tank.panzer38h_mace" ; Panzer 38h 37mm
	{clip
		{viewMin		-16}	; camera rotate upward limit (looking down)
		{viewMax		25 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	250}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 60}
		{nearoffset -10 0 55}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 40 -3 12}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_5a"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}


{"tank.panzer38h_mace2" ; Panzer 38h 37mm
	{clip
		{viewMin		-16}	; camera rotate upward limit (looking down)
		{viewMax		25 }	; camera rotate downward limit (looking up)
		{distanceMin	200}	; camera min distance from object. value / 20 = meters
		{distanceMax	250}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 75}
		{nearoffset -10 0 65}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 40 -3 12}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_tzf_5a"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 5}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}

{"vehicle.overvalwagen"
			{clip
				{viewMin		-20	}	; camera rotate upward limit (looking down)
				{viewMax		30	}	; camera rotate downward limit (looking up)
				{distanceMin	200	}	; camera min distance from object. value / 20 = meters
				{distanceMax	350	}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "basis"}
				{faroffset 0 0 60}
				{nearoffset -30 0 45}
				{camera "zoom1"}
				;{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "visor1"}
				{vignette "/texture/common/environment/lens_effects/zoom_vignette_infantry_01"}
				{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{offset -20 0 25}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 10}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
		}

{"tank.to_ku" ; 
	{clip
		{viewMin		-12	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	350	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 95}
		{nearoffset -30 0 75}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
		{no_grain}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "camera"}
		{offset 0.5 -5 2.5}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_tfmp1"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 5}
		{distanceSet 0}
		{delta 0}
		{camera "zoom1.5"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{disable_fow 0}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
	{level ;2
		{camera "zoom2.5"}
	}
}

{"vehicle.ho_ha"
			{clip
				{viewMin		-20}	; camera rotate upward limit (looking down)
				{viewMax		30 }	; camera rotate downward limit (looking up)
				{distanceMin	200}	; camera min distance from object. value / 20 = meters
				{distanceMax	350}	; camera max distance from object. value / 20 = meters
			}
			{level ;0
				{linkBone "Basis"}
				{faroffset 0 0 75}
				{nearoffset -10 0 55}
				{camera "zoom1"}
				{hide_hitmarker 1}
				{blur_strength 2}
				{disable_fow 0}
			}
			{level ;1
				{zoom}
				{vision_modes_active}
				{linkBone "mgun_rot1"}
				{vignette "/texture/common/environment/lens_effects/zoom_vignette_infantry_01"}
				{blur_mask "/texture/common/environment/lens_effects/zoom_vignette_infantry_01_mask"}
				{distance 30}
				{distanceSet 0}
				{delta 0}
				{offset -15 8 9}
				{camera "zoom1.5"}
				{ManualAccuracyZoom}
				{blur_strength 10}
				{disable_fow 0}
				{no_grain}
				{no_rim_light}
			}
		}

{"tank.so_ki"
	{clip
		{viewMin		-15	}	; camera rotate upward limit (looking down)
		{viewMax		20	}	; camera rotate downward limit (looking up)
		{distanceMin	200	}	; camera min distance from object. value / 20 = meters
		{distanceMax	300	}	; camera max distance from object. value / 20 = meters
	}
	{level ;0
		{linkBone "basis"}
		{faroffset 0 0 50}
		{nearoffset -30 0 48}
		{camera "zoom1"}
		;{hide_hitmarker 1}
		{blur_strength 2}
		{disable_fow 0}
	}
	{level ;1
		{zoom}
		{vision_modes_active}
		{linkBone "turret"}
		{offset 60 0 15}
		{scope_vignette "/texture/common/environment/lens_effects/vehicle_telescope_rus_hmg"}
		{blur_mask "/texture/common/environment/lens_effects/vehicle_telescope_mask"}
		{refraction_mask "/texture/common/environment/lens_effects/vehicle_telescope_base_bp"}
		{lens_dirt_mask "/texture/common/environment/lens_effects/dirty_lens_scope_02"}
		{distance 30}
		{distanceSet 0}
		{delta 0}
		{no_rim_light}
		{camera "zoom1"}
		{ManualAccuracyZoom}
		{blur_strength 10}
		{no_grain}
		{no_rim_light}
		{soundEffect "enclosed_vehicle"}
	}
}

