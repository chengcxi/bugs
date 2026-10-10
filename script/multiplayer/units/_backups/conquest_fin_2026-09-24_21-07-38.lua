-- File conquest.fin

Purchases["conquest.fin"] = {
	{Repeat = 0, --infinite
		Units = {
				-- ========================================================================================= part 1 =============================================================================================================================				
																																														--;		   EARLY		        MID		   LATE	
-- Infantry
--		{availability = "1.0", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Team", "Command",}, unit = "single_officer(fin)"},
--		{availability = "1.0", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Team", "Command",}, unit = "team_officer_con(fin)"},
--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad", "Command",}, unit = "squad_officer_con(fin)"},
				--T1
		{availability = "1.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad", "Partisan",}, unit = "squad_civil_guard_early_con(fin)"},					--;	1939 : 1940 : 1941 :      :      :      :      ;+
		{availability = "2.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_reserves_mid_con(fin)"},						--;	     :      :      : 1942 : 1943 :      :      ;+
				--T2
		{availability = "2.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon" }, effects = {}, type = {"Infantry", "Squad", "Recon",}, unit = "squad_scout_mid_con(fin)"},							--;	1939 : 1940 : 1941 :      :      :      :      ;+
		{availability = "2.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_rifle_early_con(fin)"},						--;	1939 : 1940 : 1941 :      :      :      :      ;+
		{availability = "2.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_rifle_lmg_early_con(fin)"},					--;	1939 : 1940 : 1941 :      :      :      :      ;+			
		{availability = "2.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_rifle_mid_con(fin)"},							--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "2.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_rifle_late_dp_con(fin)"},						--;	     :      :      :      :      : 1944 : 1945 ;+
		{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_rifle_late_dt_con(fin)"},						--;	     :      :      :      :      : 1944 : 1945 ;+
		{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_engineer_mid_con(fin)"},						--;	     :      :      : 1942 : 1943 :      :      ;+
--		{availability = "0.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_eng_flame_con(fin)"},
		{availability = "2.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_assault_mid_con(fin)"},						--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "2.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Infantry", "Squad", "AT",}, unit = "squad_antitank_late_con(fin)"},						--;	     :      :      :      :      : 1944 : 1945 ;+
				--T2+
		{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Recon" }, effects = {}, type = {"Infantry", "Squad", "Recon",}, unit = "squad_vet_scout_mid_con(fin)"},						--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_mid_con(fin)"},						--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "2.2", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_vet_rifle_late_con(fin)"},					--;	     :      :      :      :      : 1944 : 1945 ;+
		{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_marksmen_mid_con(fin)"},						--;	     :      :      : 1942 : 1943 :      :      ;+
				--T3
--		{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_border_guard_early_con(fin)"},				--Not registered
		{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_cav_mid_con(fin)"},							--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "2.2", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_cav_late_con(fin)"},							--;	     :      :      :      :      : 1944 : 1945 ;+
				--T3+
		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_vet_cav_mid_con(fin)"},						--;	     :      :      : 1942 : 1943 :      :      ;+
--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_vet_cav_late_con(fin)"},						--Not registered
		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad", "Elite",}, unit = "squad_elite_rifle_mid_con(fin)"},					--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad", "Elite",}, unit = "squad_elite_rifle_late_con(fin)"},					--;	     :      :      :      :      : 1944 : 1945 ;+
				--T4
		{availability = "1.7", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Recon" }, effects = {}, type = {"Infantry", "Squad", "Recon",}, unit = "squad_jag_scout_late_con(fin)"},					--;	     :      :      :      :      : 1944 : 1945 ;+
--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_jag_mid_con(fin)"},							--;	     :      :      : 1942 : 1943 :      :      ;+   --Not registered
--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_jag_late_con(fin)"},							--;	     :      :      :      :      : 1944 : 1945 ;+	--Not registered
--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Infantry", "Squad", "AT",}, unit = "squad_jag_at_late_con(fin)"},						--;	     :      :      :      :      : 1944 : 1945 ;+   --Not registered

--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_border_jag_mid_con(fin)"},					--;	     :      :      : 1942 : 1943 :      :      ;+
--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_border_jag_late_con(fin)"},					--;	     :      :      :      :      : 1944 : 1945 ;+   --Not registered
--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Infantry", "Squad", "AT",}, unit = "squad_border_jag_at_late_con(fin)"},				--;	     :      :      :      :      : 1944 : 1945 ;+ 	--Not registered
		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad", "Spetz",}, unit = "squad_sissi_mid_con(fin)"},							--;	     :      :      : 1942 : 1943 :      :      ;+
				--T4+
		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_vet_jag_mid_con(fin)"},						--;	     :      :      : 1942 : 1943 :      :      ;+
--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade4", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_vet_jag_late_con(fin)"},						--Not registered
				
	-- Infantry motor squads
	-- Infantry single	
		{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Infantry", "Team", "AT",}, unit = "single_at(fin)"},									--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Infantry", "Team", "AT",}, unit = "single_at_pzs_late_con(fin)"},						--;	     :      :      :      :      : 1944 : 1945 ;+
		{availability = "1.5", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Infantry", "Squad", "AT",}, unit = "squad_at_late_con(fin)"},							--;	     :      :      :      :      : 1944 : 1945 ;+
--		{availability = "1.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Team",}, unit = "single_flamer(fin)"},
		{availability = "2.0", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry" }, type = {"Infantry", "Team", "Sniper",}, unit = "single_sniper(fin)"},								--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "1.0", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon" }, effects = { "VsInfantry" }, type = {"Infantry", "Team", "Sniper",}, unit = "white_death_con(fin)"},								--;	     : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
	-- Infantry single support				
--		{availability = "1.0", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Team",}, unit = "single_medic(fin)"},
--		{availability = "0.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Team",}, unit = "single_ap_miner(fin)"},
--		{availability = "0.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Team",}, unit = "single_at_miner(fin)"},
--		{availability = "0.5", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Team",}, unit = "single_engineer(fin)"},		
--		{availability = "1.0", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Team",}, unit = "single_tankman(fin)"},
			-- Infantry squad support				
--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_heavy_engineer_mid_con(fin)"},
--		{availability = "1.0", base = { "Infantry", "Squad" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_heavy_engineer_mid_con_late(fin)"},				
--Cannons
--		{availability = "1.0", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = {}, effects = {}, type = {"Cannon", "Supply", "Ammo",}, unit = "inf_crate_fin"},
		{availability = "0.3", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = {}, effects = {}, type = {"Cannon", "Spotlight",}, maxCount = 2, cooldown = 15, unit = "150mm_sw34"},										--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
	--HMGs			2.5/2.0
		{availability = "2.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, type = {"Cannon", "MG",}, unit = "maxim_m1910_30"},									--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "2.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, type = {"Cannon", "MG",}, unit = "maxim_m32_33"},										--;	     : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+		
		{availability = "2.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, type = {"Cannon", "MG",}, unit = "mg08_fin"},											--;	     :      : 1941 : 1942 : 1943 : 1944 : 1945 ;+				

		{availability = "2.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, type = {"Cannon", "MG",}, unit = "ds39_stand_fin"},									--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
--		{availability = "0.1", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "MG" }, effects = { "VsInfantry" }, type = {"Cannon", "MG",}, unit = "panzernest_krab"},			
	--AA-guns		1.0
		{availability = "1.0", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AA",}, maxCount = 3, cooldown = 10, unit = "20mm_itk35"},										--;	1939 : 1940 : 1941 :      :      :      :      ;+
		{availability = "1.0", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AA",}, maxCount = 3, cooldown = 10, unit = "20mm_itk40"},										--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "1.0", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AA",}, maxCount = 2, cooldown = 15, unit = "40mm_itk38b"},										--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "0.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AirDefense", "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AA", "AT",}, maxCount = 2, cooldown = 15, unit = "75mm_itk37"},										--;	     :      : 1941 : 1942 : 1943 : 1944 : 1945 ;+		
		{availability = "0.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AirDefense", "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AA", "AT",}, maxCount = 2, cooldown = 15, unit = "76mm_itk31"},										--;	     :      : 1941 : 1942 : 1943 : 1944 : 1945 ;+		
	--AT-guns		2.0	
		{availability = "2.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "20mm_l39"},											--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "2.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "25mm_pstk37"},										--;	1939 :      :      :      :      :      :      ;+
		{availability = "2.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "37mm_pstk36"},										--;	1939 : 1940 :      :      :      :      :      ;+
		{availability = "2.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "76mm_k00"},											--;	1939 : 1940 :      :      :      :      :      ;+				
		{availability = "1.0", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "76mm_k36_mid"},										--;	     :      :      : 1942 : 1943 :      :      ;+	
		{availability = "1.0", base = { "Cannon" }, class = { "Light" }, grade = "Grade3", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "76mm_k36_late"},									--;	     :      :      :      :      : 1944 : 1945 ;+	
		{availability = "2.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "45mm_pstk32"},										--;	1939 :      :      :      :      :      :      ;+
		{availability = "2.0", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "47mm_pstk39"},										--;	     :      : 1941 :      :      :      :      ;+
		{availability = "2.0", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "50mm_pstk38"},										--;	     : 1940 : 1941 :      :      :      :      ;+
		{availability = "2.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "76mm_k02"},											--;	1939 : 1940 :      :      :      :      :      ;+
		{availability = "2.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "76mm_k02_30_40"},									--;	1939 : 1940 :      :      :      :      :      ;+
		{availability = "2.0", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "75mm_pstk9738"},									--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "2.0", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "76mm_k36"},											--;	     :      : 1941 : 1942 :      :      :      ;+
		{availability = "2.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "75mm_k40"},											--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "2.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Cannon", "AT",}, unit = "75mm_k44"},											--;	     :      :      :      : 1943 : 1944 : 1945 ;+			
	--Mortars
		{availability = "2.0", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, type = {"Cannon", "Mortar",}, maxCount = 7, unit = "50mm_krh38"},										--;	     : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "2.3", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, type = {"Cannon", "Mortar",}, maxCount = 5, unit = "81mm_krh36"},										--;	1939 : 1940 : 1941 : 1942 : 1943 :      :      ;+	--"no_scavenge"
		{availability = "2.0", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, type = {"Cannon", "Mortar",}, maxCount = 5, unit = "120mm_krh40"},										--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+	--"no_scavenge"
		{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, type = {"Cannon", "Mortar",}, maxCount = 4, cooldown = 5, unit = "170mm_minewerfer"},									--;	     :      : 1941 : 1942 : 1943 : 1944 : 1945 ;+	--"no_scavenge"
		{availability = "0.7", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Mortar" }, effects = { "VsInfantry" }, type = {"Cannon", "Mortar",}, maxCount = 2, unit = "300mm_krh42"},										--;	     :      :      :      :      : 1944 : 1945 ;+	--"no_scavenge"
	--Inf.Sup.Guns
		{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade1", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = {}, type = {"Cannon", "Support",}, maxCount = 3, unit = "76mm_lk13"},										--;	1939 : 1940 :      :      :      :      :      ;+
		{availability = "1.5", base = { "Cannon" }, class = { "Light" }, grade = "Grade2", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = {}, type = {"Cannon", "Support",}, maxCount = 3, unit = "76mm_m1927_fin"},									--;	1939 : 1940 :      :      :      :      :      ;+
		{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = {}, type = {"Cannon", "Support",}, maxCount = 3, unit = "84mm_k18"},											--;	     :      : 1941 : 1942 : 1943 :      :      ;+
		{availability = "1.5", base = { "Cannon" }, class = { "Medium" }, grade = "Grade3", posture = { "Defensive" }, roles = { "InfantryGun" }, effects = {}, type = {"Cannon", "Support",}, maxCount = 3, unit = "84mm_k18_late"},									--;	     :      :      :      :      : 1944 : 1945 ;+			
	--Artillery
--		{availability = "0.9", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, mult = 2, maxCount = 4, unit = "105mm_k13"},										--;	     :      : 1941 : 1942 :      :      :      ;+
--		{availability = "0.9", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, maxCount = 3, unit = "105mm_h33"},										--;	     :      :      :      : 1943 : 1944 : 1945 ;+
		{availability = "0.9", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, mult = 2, maxCount = 4, unit = "105mm_k34"},										--;	     :      : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "0.9", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, mult = 2, maxCount = 4, unit = "107mm_k10"},										--;	1939 : 1940 :      :      :      :      :      ;+
--		{availability = "0.9", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, maxCount = 2, unit = "120mm_k78_31"},										--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+
--		{availability = "0.9", base = { "Cannon" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, maxCount = 2, unit = "122mm_m1910_fin"},									--;	     :      : 1941 : 1942 :      :      :      ;+
		{availability = "0.8", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, maxCount = 2, unit = "150mm_h40"},										--;	     :      :      :      :      : 1944 : 1945 ;+
		{availability = "0.8", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, maxCount = 2, unit = "155mm_h17"},										--;	     :      :      :      : 1943 : 1944 : 1945 ;+
--		{availability = "0.3", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, unit = "155mm_k17"},										--;	     :      :      :      :      : 1944 : 1945 ;+
--		{availability = "0.3", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, unit = "203mm_h17"},										--;	     :      : 1941 : 1942 : 1943 : 1944 : 1945 ;+
--		{availability = "0.3", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade2", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "Howitzer",}, unit = "210mm_h17"},										--;	     :      :      :      : 1943 : 1944 : 1945 ;+
		-- Rocket Artillery
		{availability = "1.3", base = { "Cannon" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "MLRS",}, maxCount = 5, cooldown = 5, unit = "150mm_rkh41"},										--;	     :      : 1941 : 1942 : 1943 : 1944 : 1945 ;+	--"no_scavenge"			
-- Wheel vehicles
		{availability = "1.0", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Vehicle", "Unarmed", "Transport",}, mult = 5, maxCount = 5, unit = "m42_truppenfahrrad"},								--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "0.3", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Vehicle", "Unarmed", "Transport",}, mult = 4, maxCount = 4, unit = "ford_v3000"},										--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "0.1", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, maxCount = 1, unit = "ford_v3000_ammo"},									--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "0.2", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Vehicle", "Unarmed", "Supply", "Fuel",}, maxCount = 2, cooldown = 15, unit = "ford_v3000_fuel"},									--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "0.4", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Vehicle", "Unarmed", "Supply", "Engineer",}, mult = 2, maxCount = 4, cooldown = 10, unit = "ford_v3000_eng"},									--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
	-- AA vehicles	
		{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsVehicle", "VsArmor" }, type = {"Vehicle", "AA",}, cooldown = 5, unit = "ford_3ton_breda"},									--;	     : 1940 : 1941 : 1942 : 1943 : 1944 :      ;+	
		{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsVehicle", "VsArmor" }, type = {"Vehicle", "AA",}, cooldown = 5, unit = "volvo_127d_itk40"},									--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+
				
-- BTR			0.5-1.0	
		{availability = "1.3", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, type = {"Armored", "MG",}, mult = 2, unit = "l182"},												--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "1.3", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Armored",}, mult = 2, unit = "ba6_fin"},											--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 :      ;+
		{availability = "1.3", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Armored",}, mult = 2, unit = "ba10_fin"},											--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "1.3", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Armored",}, mult = 2, unit = "ba10_fin_mid"},										--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "1.3", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Armored",}, mult = 2, unit = "ba10m_fin"},										--;	     :      :      :      :      : 1944 : 1945 ;+
			-- Support		  0.1		
-- Halftracks		
-- Tanks
	-- Light tanks		
--		{availability = "0.3", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light",}, unit = "ft17_mg_fin"},										--;	1939 :      :      :      :      :      :      ;+
		{availability = "0.3", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light",}, unit = "t37a_fin"},											--;	1939 : 1940 : 1941 :      :      :      :      ;+
--		{availability = "0.5", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light",}, unit = "ft17_fin"},											--;	1939 :      :      :      :      :      :      ;+
	-- Light tanks
		{availability = "2.0", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "vickers_6t_altb"},									--;	1939 : 1940 : 1941 :      :      :      :      ;+
		{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "t26e"},												--;	     : 1940 : 1941 :      :      :      :      ;+
		{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "t26e_mid"},											--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "0.5", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "t26_33_fin"},										--;	     : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "t26_33_fin_mid"},									--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "t26c"},												--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "bt5_fin"},											--;	     : 1940 : 1941 :      :      :      :      ;+
		{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "bt5_fin_mid"},										--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "0.5", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "kht130_fin"},										--;	     : 1940 : 1941 : 1942 :      :      :      ;+
		{availability = "2.0", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "t50_fin"},											--;	     :      : 1941 : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Light", "Main",}, unit = "l62"},												--;	     :      :      :      : 1943 : 1944 : 1945 ;+				
		{availability = "0.3", base = { "Vehicle" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, type = {"Armored", "MG",}, unit = "t20_fin"},											--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+	
	-- Rocket Light	
	-- Medium tanks		
		{availability = "2.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Medium", "Main",}, cooldown = 3, unit = "t28_38_fin"},										--;	1939 : 1940 : 1941 : 1942 :      :      :      ;+
		{availability = "2.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Medium", "Main",}, cooldown = 5, unit = "t28e_fin"},											--;	     :      :      : 1942 : 1943 :      :      ;+
		{availability = "2.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Medium", "Main",}, cooldown = 5, unit = "t28e_fin_late"},									--;	     :      :      :      : 1943 : 1944 : 1945 ;+	
		{availability = "2.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Medium", "Main",}, unit = "t3476_41_fin"},										--;	     :      : 1941 : 1942 : 1943 :      :      ;+
		{availability = "2.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Medium", "Main",}, unit = "t3476_41_fin_late"},								--;	     :      :      :      :      : 1944 : 1945 ;+	
		{availability = "2.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Medium", "Main",}, unit = "panzer4j_fin"},										--;	     :      :      :      : 1943 : 1944 : 1945 ;+
		{availability = "2.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Medium", "Main",}, unit = "t3485_44_fin"},										--;	     :      :      :      :      : 1944 : 1945 ;+				
	-- Heavy tanks
		{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Heavy", "Main",}, maxCount = 3, cooldown = 10, unit = "kv1_40e_fin"},										--;	     : 1940 : 1941 : 1942 :      :      :      ;+	--"no_scavenge"
		{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Heavy", "Main",}, maxCount = 3, cooldown = 15, unit = "kv1_40e_fin_late"},									--;	     :      :      : 1942 : 1943 :      :      ;+	--"no_scavenge"
		{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade2", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Heavy", "Main",}, maxCount = 5, cooldown = 7, unit = "kv1_42_fin"},										--;	     :  	:      : 1942 : 1943 : 1944 : 1945 ;+	--"no_scavenge"
		{availability = "1.5", base = { "Tank" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Heavy", "Main",}, maxCount = 5, cooldown = 7, unit = "kv1_42_fin_late"},										--;	     :      :      :      :      : 1944 : 1945 ;+	--"no_scavenge"
-- SPG
	-- SPG-Art.
	-- SPG-Sup.
		{availability = "1.3", base = { "Tank" }, class = { "Light" }, grade = "Grade1", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = {}, type = {"Tank", "Light", "Support",}, cooldown = 3, unit = "bt42"},												--;	     :      : 1941 : 1942 : 1943 : 1944 : 1945 ;+	--"no_scavenge"
	-- SPG-AA.
	-- SPG-AT-Support	
	-- SPG Reactive
	-- SPG-AT
		{availability = "2.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Tank", "Medium", "AT", "TD",}, unit = "stug3g_fin_early"},									--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "2.5", base = { "SPG" }, class = { "Medium" }, grade = "Grade2", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Tank", "Medium", "AT", "TD",}, unit = "stug3g_fin"},										--;	     :      :      :      : 1943 : 1944 : 1945 ;+
		{availability = "1.5", base = { "SPG" }, class = { "Heavy" }, grade = "Grade3", posture = { "Flexible" }, roles = { "AntiTank" }, effects = { "VsVehicle", "VsArmor" }, type = {"Tank", "Heavy", "AT", "TD",}, unit = "isu152_fin"},									--;	     :      :      :      :      : 1944 : 1945 ;+	--"no_scavenge"
		-- ========================================================================================= part 2 ==================================================================================================================================		
																																														-- ===================================================
																																															--;EARLY		         MID		   LATE	
-- Aircraft
	--Recon
		{availability = "2.5", base = { "Aircraft" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Recon" }, effects = {}, type = {"Aircraft", "ReconPlane",}, maxCount = 12, cooldown = 7, unit = "po2_fin_ai"},										--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
	--Fighters-assault		
		{availability = "3.5", base = { "Aircraft" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Aircraft", "_Fighter",}, mult = 2, maxCount = 12, cooldown = 7, unit = "fokker_fin_ai"},									--;	1939 : 1940 : 1941 : 1942 : 1943 :      :      ;		;4.0
		{availability = "3.5", base = { "Aircraft" }, class = {}, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Aircraft", "_Fighter",}, mult = 2, maxCount = 10, cooldown = 7, unit = "bf109_g6_fin_ai"},									--;	     :      :      :      :      : 1944 : 1945 ;		;4.0
	--Heavy Assault	
	--Light bombers
	--Medium bombers	
	--Para-planes
																																																									
-- Infantry
	-- Infantry squads	
		{availability = "3.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad", "Reg", "Full",}, unit = "squad_arm_fin_regular_1939(fin)"},					--;	1939 : 1940 :      :      :      :      :      ;+
		{availability = "3.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad", "Reg", "Full",}, unit = "squad_arm_fin_regular_1941(fin)"},					--;	     :      : 1941 : 1942 :      :      :      ;+
		{availability = "3.3", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad", "Reg", "Full",}, unit = "squad_arm_fin_regular_1943(fin)"},					--;	     :      :      :      : 1943 : 1944 : 1945 ;+
		{availability = "2.7", base = { "Infantry", "Squad" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_arm_fin_border_1939(fin)"},					--;	1939 : 1940 : 1941 :      :      :      :      ;+
		{availability = "2.7", base = { "Infantry", "Squad" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Squad",}, unit = "squad_arm_fin_border_1942(fin)"},					--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+				
	-- Infantry single support				
		{availability = "1.0", base = { "Infantry", "Single" }, class = {}, grade = "Grade1", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Team", "Signal",}, unit = "squad_fin_signaller(fin)"},							--;	     : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+
--		{availability = "0.3", base = { "Infantry", "Single" }, class = {}, grade = "Grade2", posture = { "Flexible" }, roles = { "Line" }, effects = {}, type = {"Infantry", "Team",}, unit = "single_signaller_nobuy(fin)"},						
--Cannons
-- Artillery
	--Rocket Artillery
		{availability = "1.3", base = { "Cannon" }, class = { "Heavy" }, grade = "Grade3", posture = { "Defensive" }, roles = { "Artillery" }, effects = {}, type = {"Cannon", "Artillery", "MLRS",}, mult = 2, maxCount = 6, unit = "280mm_rakh43"},										--;	     :      :      :      :      : 1944 : 1945 ;+

	-- Wheeled vehicles
		{availability = "0.2", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = {}, type = {"Vehicle", "Unarmed", "Supply", "Ammo",}, maxCount = 2, cooldown = 15, unit = "volvo_weapon"},										--;	1939 : 1940 : 1941 : 1942 : 1943 : 1944 : 1945 ;+

	-- BTR
		{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade1", posture = { "Defensive" }, roles = { "AirDefense" }, effects = { "VsVehicle", "VsArmor" }, type = {"Vehicle", "AA", "Armored",}, unit = "lvtdgb_m40"},										--;	     : 1940 : 1941 : 1942 : 1943 :      :      ;+
		{availability = "1.5", base = { "Vehicle" }, class = { "Medium" }, grade = "Grade1", posture = { "Flexible" }, roles = { "MG" }, effects = { "VsInfantry" }, type = {"Armored", "MG",}, unit = "pbil_m40"},											--;	     :      : 1941 : 1942 : 1943 : 1944 : 1945 ;+			
	-- SPG
		{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade2", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = {}, type = {"Tank", "Light", "Support", "Prototype",}, mult = 2, maxCount = 4, cooldown = 5, unit = "stormpjas_fm_43"},									--;	     :      :      : 1942 : 1943 : 1944 : 1945 ;+
		{availability = "1.5", base = { "Tank" }, class = { "Light" }, grade = "Grade3", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = {}, type = {"Tank", "Light", "Support",}, unit = "sav_m43_1944"},										--;	     :      :      :      :      : 1944 : 1945 ;+
--		{availability = "0.7", base = { "Tank" }, class = { "Light" }, grade = "Grade4", posture = { "Flexible" }, roles = { "InfantryGun" }, effects = {}, type = {"Tank", "Light", "Support",}, unit = "sav_m43_1946"},										--;	     :      :      :      :      :      : 1945 ;+
-- Tanks
	--Medium tanks
		{availability = "2.5", base = { "Tank" }, class = { "Medium" }, grade = "Grade3", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Medium", "Main",}, mult = 3, maxCount = 9, cooldown = 5, unit = "comet"},											--;	      :     :      :      :      : 1944 : 1945 ;+
	--Heavy tanks
		{availability = "1.2", base = { "Tank" }, class = { "Heavy" }, grade = "Grade1", posture = { "Flexible" }, roles = {}, effects = { "VsInfantry", "VsVehicle", "VsArmor" }, type = {"Tank", "Heavy", "Main", "Prototype",}, maxCount = 1, unit = "smk_fin"}											--;	1939 : 1940 :      :      :      :      :      ;+	--"no_scavenge"	;//END!

			}
	}
}		
